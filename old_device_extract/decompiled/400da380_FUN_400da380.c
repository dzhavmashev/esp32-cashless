// Function : FUN_400da380
// Address  : 0x400da380
// Size     : 122 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400da380(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_34 [8];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  uStack_2c = 0;
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(code **)(param_2 + 8) != (code *)0x0) {
    (**(code **)(param_2 + 8))(auStack_34,param_2,2);
    uStack_28 = *(undefined4 *)(param_2 + 0xc);
    uStack_2c = *(undefined4 *)(param_2 + 8);
  }
  FUN_400d73b8(auStack_34,param_1 + 0x4c);
  uVar2 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x54) = uStack_2c;
  uVar3 = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x58) = uStack_28;
  uStack_2c = uVar2;
  uStack_28 = uVar3;
  (*(code *)&LAB_40183a17_1)(auStack_34);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    (*(code *)&LAB_40183a17_1)(auStack_34);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

