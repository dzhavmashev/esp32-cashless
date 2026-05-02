// Function : FUN_40133dcc
// Address  : 0x40133dcc
// Size     : 132 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40133dcc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_44 [32];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b530)(auStack_44,0,0x20);
  FUN_4013ce78(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x44) = param_2;
  *(undefined4 *)(param_1 + 0x48) = param_3;
  if (*(int *)(param_1 + 0x18) == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0x30;
  }
  uVar2 = *(uint *)(param_1 + 0x10);
  if ((int)uVar2 < 0) {
    uVar2 = 0;
    if (*(uint *)(param_1 + 0x18) < 0x30) {
      uVar2 = *(uint *)(param_1 + 0x18) + 1 >> 1;
    }
  }
  memw();
  iVar1 = FUN_4013cea0(param_1 + 0x20,auStack_44,0x100);
  if (iVar1 == 0) {
    iVar1 = FUN_40133c98(param_1,param_4,param_5,uVar2);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

