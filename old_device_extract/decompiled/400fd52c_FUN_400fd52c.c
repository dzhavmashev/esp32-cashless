// Function : FUN_400fd52c
// Address  : 0x400fd52c
// Size     : 110 bytes


void FUN_400fd52c(void)

{
  char local_30 [8];
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  builtin_strncpy(local_30,"_init",6);
  local_30[6] = '\0';
  local_30[7] = '\0';
  uStack_28 = 1;
  uStack_24 = 0x3ff5f000;
  memw();
  (*(code *)&SUB_4009386c)(local_30,1,40000,0);
  (*(code *)&SUB_40093c14)(local_30);
  (*(code *)&SUB_40093abc)(local_30,0,2000,3);
  (*(code *)&SUB_40093c38)(local_30);
  (*(code *)&SUB_40093d88)(local_30);
  (*(code *)&SUB_40093c14)(&uStack_28);
  (*(code *)&SUB_40093c88)(&uStack_28);
  (*(code *)&SUB_40093d88)(&uStack_28);
  return;
}

