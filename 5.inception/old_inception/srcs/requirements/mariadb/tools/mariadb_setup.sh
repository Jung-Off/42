#!/bin/sh

service mysql start;

cat /var/lib/mysql/.setup 2> /dev/null
# cat의 표준출력을 표준에러로 /dev/null 파일로 출력한다.
# 파일이 있으면 아무런 메세지도 출력하지 않지만, 파일이 없으면 에러가 출력된다.
# cat을 이용해 파일이 있는지 없는지 체크하는 것.
# https://blogger.pe.kr/369
# 이를 이용해 db가 사용자 정의 파일로 이미 설정되었는지 여부 확인한다.

if [ $? -ne 0 ]; then
# 쉘스크립트의 if문
# -ne : 값이 다르면 (not equl)
# -eq : 값이 같으면 (equl)

# 쉘 스크립트 특별 변수
# - $? :직전에 실행한 커맨드의 종료 값(0은 성공, 1은 실패)
# 출처: https://engineer-mole.tistory.com/200

# -e (--execute=) : 쉘스크립트나 CLI에서 mysql 명령어를 '실행'할 때 사용하는 명령어
#					https://seul96.tistory.com/332

	mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE";
	mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'";
	mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'";
	mysql -e "FLUSH PRIVILEGES";
	mysql -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'";

	mysql $MYSQL_DATABASE -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD
	mysqladmin -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD shutdown

	touch /var/lib/mysql/.setup
fi

exec mysqld --console
# MySQL + Daemon
# https://velog.io/@seomoon/mysql-mysqld