// Function : FUN_400def94
// Address  : 0x400def94
// Size     : 158 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400def94(int param_1)

{
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  if (*(char *)(param_1 + 0x88) != '\0') {
    memw();
    *(undefined1 *)(param_1 + 0x88) = 0;
    if ((*(int *)(param_1 + 0xc) != 0) && (*(char *)(param_1 + 0x89) != '\0')) {
      FUN_400f0be8(auStack_34,param_1 + 0x89);
      memw();
      uStack_38 = *(undefined4 *)(param_1 + 0xf0);
      memw();
      uStack_3a = *(undefined2 *)(param_1 + 0xf4);
      if (*(int *)(param_1 + 0xc) == 0) {
        FUN_40170584();
        FUN_400f0a50(auStack_34);
        thunk_FUN_401710d8(param_1);
      }
      (**(code **)(param_1 + 0x10))(param_1 + 4,auStack_34,&uStack_38,&uStack_3a);
      *(undefined1 *)(param_1 + 0x89) = 0;
      memw();
      *(undefined4 *)(param_1 + 0xf0) = 0;
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

