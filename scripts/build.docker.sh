#!/bin/sh

SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"
WORKDIR="$(dirname "$SCRIPT_DIR")"

# 确保工作目录正确
cd "$WORKDIR" || exit 1

# 构建 Docker 镜像
docker buildx build \
	--platform linux/amd64 \
	--build-arg "THREADS=$(nproc)" \
	--build-context workdir="$WORKDIR" \
	-f scripts/Dockerfile \
	-t subconverter:latest \
	--progress=plain \
	.
