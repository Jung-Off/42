
DB_LOCAL_PATH = /Users/jji/42/5.inception/data

NAME	= inception

#evaltion
# DB_PATH	= /home/jji/data

BLUE	= \033[36m
COLR	= \033[0m

all		:	$(NAME)

$(NAME)	:
	# mkdir -p $(DB_PATH)/mariadb/
	# mkdir -p $(DB_PATH)/wordpress/
	mkdir -p /Users/jji/42/5.inception/data/wordpress
	mkdir -p /Users/jji/42/5.inception/data/mariadb
	# sudo echo "127.0.0.1	jji.42.fr" > /etc/hosts
	docker-compose -f srcs/docker-compose.yml up --build

# help	: ## 실행가능한 명령을 출력
# 	@echo " make [command]"
# 	@egrep -h '\s##\s' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "$(BLUE) %-5s$(COLR) \t%s\n", $$1, $$2}'

down	: ## 컨테이너들을 일괄 정지
	@echo "Down all"
	docker-compose -f srcs/docker-compose.yml down

clean	: ## 컨테이너를 일괄정지 하고 모든 이미지와 연결된 볼륨 전부 삭제
	docker-compose -f srcs/docker-compose.yml down --rmi "all" --volumes

fclean	: clean ## ⚠️로컬 볼륨 파일까지 전부 삭제
	rm -rf /Users/jji/42/5.inception/data
	# rm -rf /Users/jji/42/5.inception/data/mariadb/.setup
	# rm -rf /Users/jji/42/5.inception/data/mariadb/*
	# rm -rf /Users/jji/42/5.inception/data/wordpress/.setup
	# rm -rf /Users/jji/42/5.inception/data/wordpress/*

re	: fclean all ## fclean 실행 후 다시 make 실행



# .PHONY:	 all up fclean



# all:
# 		# mkdir -p /home/jji/data/wordpress
# 		# mkdir -p /home/jji/data/mariadb

# 		mkdir -p /Users/jji/42/5.inception/data/wordpress
# 		mkdir -p /Users/jji/42/5.inception/data/mariadb
# 		# echo "127.0.0.1 seshin.42.fr" >> /etc/hosts
# 		docker-compose -f srcs/docker-compose.yml up --build

# up:
# 		docker-compose -f srcs/docker-compose.yml up --build

# fclean:	
# 		docker-compose -f srcs/docker-compose.yml down --rmi all --volumes
# 		# docker rmi debian:buster
# 		rm -rf /Users/jji/42/5.inception/data