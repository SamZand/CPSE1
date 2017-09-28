.PHONY: clean All

All:
	@echo "----------Building project:[ Week_3-1 -  ]----------"
	@cd "Week_3-1" && "$(MAKE)" -f  "Week_3-1.mk"
clean:
	@echo "----------Cleaning project:[ Week_3-1 -  ]----------"
	@cd "Week_3-1" && "$(MAKE)" -f  "Week_3-1.mk" clean
