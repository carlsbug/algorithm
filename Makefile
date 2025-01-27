IMAGE_NAME=linux_gdb
TAG=latest  # TAG 변수를 추가

# Docker 이미지를 빌드
build:
	docker build -t $(IMAGE_NAME):$(TAG) .

# Docker 컨테이너 실행
run:
	docker run -it $(IMAGE_NAME):$(TAG)

# Docker 컨테이너 중지 및 삭제, 이미지 삭제
clean:
	docker stop $(IMAGE_NAME) && docker rm $(IMAGE_NAME)
	docker rmi $(IMAGE_NAME):$(TAG)

.PHONY: build run clean