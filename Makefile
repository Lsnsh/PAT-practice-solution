# 指定默认目标
.DEFAULT_GOAL := nb
# 指定伪目标（目录下存在同名文件也会继续执行）
.Phony: ns na nb clean debug

ns:
	@echo "顶级"


na:
	@echo "甲级"


# make name="1005 继续(3n+1)猜想 (25 分)"
#题目名称：1005 继续(3n+1)猜想 (25 分)
#touch "src/PAT (Basic Level) Practice （中文）/1005.继续(3n+1)猜想 (25 分)".c
nb:
ifdef name
	@echo "乙级-题目名称：$(name)"
	touch "src/PAT (Basic Level) Practice （中文）/$(subst $(word 1, $(name)) ,$(word 1, $(name)).,$(name))".c
	echo "- [$(subst $(word 1, $(name)) ,$(word 1, $(name)).,$(name))]()" >> "src/PAT (Basic Level) Practice （中文）/README.md"
else
	@echo "请输入题目名称"
endif

clean:
	rm -rf "src/PAT (Basic Level) Practice （中文）/_out"
	mkdir -p "src/PAT (Basic Level) Practice （中文）/_out"

debug:
	touch "$(subst $(word 1, $(name)) ,$(word 1, $(name)).,$(name))".c
