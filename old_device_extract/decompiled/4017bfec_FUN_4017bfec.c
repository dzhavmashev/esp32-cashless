// Function : FUN_4017bfec
// Address  : 0x4017bfec
// Size     : 51 bytes


char * FUN_4017bfec(undefined4 param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = "VALID_MAC";
  if (param_3 != 0) {
    iVar2 = (*(code *)&SUB_4008bdec)(param_3,"cceeded");
    pcVar1 = "VALID_MAC";
    if (iVar2 != 0) {
      iVar2 = (*(code *)&SUB_4008bdec)(param_3,"VALID_MAC");
      pcVar1 = "VALID_MAC";
      if (iVar2 != 0) {
        iVar2 = (*(code *)&SUB_4008bdec)(param_3,&DAT_3f42161d);
        pcVar1 = "VALID_MAC";
        if (iVar2 != 0) {
          pcVar1 = (char *)0x0;
        }
      }
    }
  }
  return pcVar1;
}

