// Function : FUN_400d8e1c
// Address  : 0x400d8e1c
// Size     : 178 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d8e1c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uVar1 = *param_2;
  FUN_400f0780(0x3ffc5490,"ls: %s\n");
  FUN_400f06a4(0x3ffc5490,&DAT_3f403b3d);
  FUN_400f06a4(0x3ffc5490,&DAT_3f4039ae,uVar1);
  FUN_400f0780(0x3ffc5490,&DAT_3f4039f5);
  iVar2 = *param_1;
  FUN_400f0be8(auStack_34,&DAT_3f403b8b);
  FUN_400d8d08(iVar2,uVar1,auStack_34);
  FUN_400f0a50(auStack_34);
  if ((*(int **)(*param_1 + 0x28) != (int *)0x0) &&
     (iVar2 = (**(code **)(**(int **)(*param_1 + 0x28) + 0x14))(), iVar2 == 3)) {
    FUN_400dd968(*(undefined4 *)(*param_1 + 0x28));
    FUN_400f0780(0x3ffc5490,&DAT_3f403b90);
  }
  iVar2 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    thunk_FUN_401710d8(iVar2);
  }
  return;
}

