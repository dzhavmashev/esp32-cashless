// Function : FUN_401271a4
// Address  : 0x401271a4
// Size     : 129 bytes


void FUN_401271a4(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x48), iVar1 != 0)) {
    FUN_40128cf8(*(undefined4 *)(iVar1 + 0x40));
    FUN_40128a7c(*(undefined4 *)(iVar1 + 0x54),0);
    FUN_40128a7c(*(undefined4 *)(iVar1 + 0x58),0);
    FUN_40128a7c(*(undefined4 *)(iVar1 + 0x3c),1);
    FUN_40128a7c(*(undefined4 *)(iVar1 + 0x38),1);
    FUN_40128a7c(*(undefined4 *)(iVar1 + 0x20),0);
    FUN_40128a7c(*(undefined4 *)(iVar1 + 0x24),0);
    FUN_40128a7c(*(undefined4 *)(iVar1 + 0x2c),0);
    FUN_40128d84(*(undefined4 *)(iVar1 + 0x34),1);
    FUN_40128d84(*(undefined4 *)(iVar1 + 0x28),0);
    FUN_40128d84(*(undefined4 *)(iVar1 + 0x30),0);
    FUN_4010531c(*(undefined4 *)(iVar1 + 100));
    FUN_4010531c(*(undefined4 *)(iVar1 + 0x68));
    (*(code *)&SUB_40094d80)(*(undefined4 *)(iVar1 + 0x5c));
    FUN_4010529c(iVar1,0x70);
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  memw();
  return;
}

