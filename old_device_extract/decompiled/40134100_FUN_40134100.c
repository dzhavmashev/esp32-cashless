// Function : FUN_40134100
// Address  : 0x40134100
// Size     : 73 bytes


int FUN_40134100(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = param_1 + 1;
  iVar1 = FUN_40133f7c(puVar3,param_2,param_3);
  if ((iVar1 == 0) && (iVar1 = FUN_40133f7c(param_1 + 4,param_2,param_3), iVar1 == 0)) {
    iVar1 = FUN_40133f7c(param_1 + 0xd,param_2,param_3);
    if ((iVar1 == 0) && (iVar1 = FUN_40133fd4(param_1 + 0xd,puVar3), iVar1 == 0)) {
      uVar2 = FUN_401317d8(puVar3);
      *param_1 = uVar2;
    }
  }
  memw();
  return iVar1;
}

