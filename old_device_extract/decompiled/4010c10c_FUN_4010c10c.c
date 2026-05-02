// Function : FUN_4010c10c
// Address  : 0x4010c10c
// Size     : 50 bytes


int FUN_4010c10c(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_4010bbc4(param_1,*(undefined2 *)(param_3 + 8),param_2);
  if ((iVar2 != 0) && (cVar1 = FUN_4010bf9c(iVar2,param_3), cVar1 != '\0')) {
    (*(code *)&SUB_40094c54)("if_init",0x54f," failed"," result");
  }
  return iVar2;
}

