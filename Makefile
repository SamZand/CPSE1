.PHONY: clean All

All:
	@echo "----------Building project:[ Week_1-1 - Release ]----------"
	@cd "Week_1-1" && "$(MAKE)" -f  "Week_1-1.mk"
clean:
	@echo "----------Cleaning project:[ Week_1-1 - Release ]----------"
	@cd "Week_1-1" && "$(MAKE)" -f  "Week_1-1.mk" clean
