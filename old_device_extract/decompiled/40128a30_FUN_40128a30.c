// Function : FUN_40128a30
// Address  : 0x40128a30
// Size     : 40 bytes


int FUN_40128a30(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)&SUB_40094dd8)(1,0xc);
  if ((iVar1 != 0) && (iVar2 = FUN_4013183c(iVar1,param_1,param_2), iVar2 != 0)) {
    (*(code *)&SUB_40094d80)(iVar1);
    iVar1 = 0;
  }
  return iVar1;
}

