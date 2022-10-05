.PHONY:	 all up fclean

all:
		@sudo docker-compose -f srcs/docker-compose.yml up --build -d
up:
		@sudo docker-compose -f srcs/docker-compose.yml up --build -d

fclean:
		@sudo docker-compose -f srcs/docker-compose.yml down --rmi all
		# @sudo docker rmi debian:buster 이건 왜 지워야되는 거야