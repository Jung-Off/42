FROM 	debian:buster

RUN		apt-get update && apt-get -y upgrade
RUN		apt-get -y install\
		nginx \
		mariadb-server \
		php-mysql \
		openssl \
		vim \
		wget \
		php7.3-fpm

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE	80 443

CMD 	bash run.sh
