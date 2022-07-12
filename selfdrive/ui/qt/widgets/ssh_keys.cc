#include "selfdrive/ui/qt/widgets/ssh_keys.h"

#include "selfdrive/common/params.h"
#include "selfdrive/ui/qt/api.h"
#include "selfdrive/ui/qt/widgets/input.h"

SshControl::SshControl() : ButtonControl("SSH 키", "", "경고: 이렇게 하면 GitHub 설정의 모든 공개 키에 SSH 액세스 권한이 부여됩니다. 자신의 GitHub 사용자 이름이 아닌 다른 사용자 이름을 입력하지 마십시오. 콤마 직원은 GitHub 사용자 이름을 추가하도록 요청하지 않습니다.") {
  username_label.setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  username_label.setStyleSheet("color: #aaaaaa");
  hlayout->insertWidget(1, &username_label);

  QObject::connect(this, &ButtonControl::clicked, [=]() {
    if (text() == "추가") {
      QString username = InputDialog::getText("GitHub 아이디를 입력하세요", this);
      if (username.length() > 0) {
        setText("읽어오는중");
        setEnabled(false);
        getUserKeys(username);
      }
    } else {
      params.remove("GithubUsername");
      params.remove("GithubSshKeys");
      refresh();
    }
  });

  refresh();
}

void SshControl::refresh() {
  QString param = QString::fromStdString(params.get("GithubSshKeys"));
  if (param.length()) {
    username_label.setText(QString::fromStdString(params.get("GithubUsername")));
    setText("제거");
  } else {
    username_label.setText("");
    setText("추가");
  }
  setEnabled(true);
}

void SshControl::getUserKeys(const QString &username) {
  HttpRequest *request = new HttpRequest(this, false);
  QObject::connect(request, &HttpRequest::requestDone, [=](const QString &resp, bool success) {
    if (success) {
      if (!resp.isEmpty()) {
        params.put("GithubUsername", username.toStdString());
        params.put("GithubSshKeys", resp.toStdString());
      } else {
        ConfirmationDialog::alert(QString("Username '%1' 의 키가 GitHub에 없습니다").arg(username), this);
      }
    } else {
      if (request->timeout()) {
        ConfirmationDialog::alert("타임아웃이 발생하였습니다", this);
      } else {
        ConfirmationDialog::alert(QString("Username '%1' 은 GitHub의 회원이 아닙니다").arg(username), this);
      }
    }

    refresh();
    request->deleteLater();
  });

  request->sendRequest("https://github.com/" + username + ".keys");
}
