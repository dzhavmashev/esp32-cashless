// Function : FUN_400e073c
// Address  : 0x400e073c
// Size     : 44 bytes


undefined4 FUN_400e073c(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar1 = param_1[1];
  FUN_400d48f8(iVar3 + 0x18,iVar1);
  iVar2 = (*(code *)&LAB_4018416e_2)();
  if (iVar2 != 0) {
    FUN_400d48f8(iVar3 + 0x18,iVar1);
    param_2 = FUN_400e0588();
  }
  return param_2;
}

