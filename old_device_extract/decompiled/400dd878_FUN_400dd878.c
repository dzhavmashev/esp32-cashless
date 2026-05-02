// Function : FUN_400dd878
// Address  : 0x400dd878
// Size     : 159 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400dd878(int param_1)

{
  ulonglong uVar1;
  bool bVar2;
  float fVar3;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  if (*(char *)(param_1 + 0x3d) != '\0') {
    memw();
    *(undefined1 *)(param_1 + 0x3d) = 0;
    memw();
    fVar3 = (float)FUN_40187018(*(undefined4 *)(param_1 + 0xa4),*(undefined4 *)(param_1 + 0x30));
    uVar1 = (ulonglong)(fVar3 * 1.0);
    bVar2 = uVar1 >> 0x10 != 0;
    *(uint *)(param_1 + 0x2c) =
         *(int *)(param_1 + 0x2c) +
         ((uint)((longlong)uVar1 < 0) * -0x80000000 - (uint)(NAN(fVar3) || bVar2)) +
         (uint)((!NAN(fVar3) && !bVar2) && (longlong)uVar1 >= 0) * (int)uVar1;
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_400f0be8(auStack_34,param_1 + 0x3e);
      memw();
      uStack_38 = *(undefined4 *)(param_1 + 0xa4);
      uStack_3a = 0;
      if (*(int *)(param_1 + 0xc) == 0) {
        FUN_40170584();
        FUN_400f0a50(auStack_34);
        thunk_FUN_401710d8(param_1);
      }
      (**(code **)(param_1 + 0x10))(param_1 + 4,auStack_34,&uStack_38,&uStack_3a);
      FUN_400f0a50(auStack_34);
    }
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

