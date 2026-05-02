// Function : FUN_400d73f0
// Address  : 0x400d73f0
// Size     : 114 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d73f0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [8];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_2c = 0;
  if (*(code **)(param_2 + 8) != (code *)0x0) {
    (**(code **)(param_2 + 8))(auStack_34,param_2,2);
    uStack_28 = *(undefined4 *)(param_2 + 0xc);
    uStack_2c = *(undefined4 *)(param_2 + 8);
  }
  FUN_400d73b8(auStack_34,param_1);
  uVar1 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = uStack_2c;
  uVar2 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = uStack_28;
  uStack_2c = uVar1;
  uStack_28 = uVar2;
  (*(code *)&LAB_40183a17_1)(auStack_34);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    (*(code *)&LAB_40183a17_1)(auStack_34);
    thunk_FUN_401710d8(param_1);
  }
  return;
}

