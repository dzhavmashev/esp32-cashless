// Function : FUN_400dcc90
// Address  : 0x400dcc90
// Size     : 455 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400dcc90(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined1 auStack_58 [20];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(int *)(param_1 + 0x1c) == 0) goto LAB_400dce42;
  FUN_400d7378(auStack_78,0x100,0);
  if (*(int *)(param_1 + 0x3c) == *(int *)(param_1 + 0x40)) {
    FUN_400f0be8(auStack_44,&DAT_3f42161d);
  }
  else {
    FUN_400f0d4c(auStack_44);
  }
  uVar2 = FUN_400d4db0(auStack_58,"ncy",auStack_70);
  FUN_40183db8(auStack_44,uVar2,auStack_70);
  FUN_400f0a50(auStack_44);
  iVar3 = FUN_400f11c0(param_2,"rPaused");
  if (iVar3 == 0) {
    uVar1 = *(undefined1 *)(param_1 + 0x6e);
    uVar2 = FUN_400d4db0(auStack_58,"try",auStack_70);
    (*(code *)&LAB_40183f5a_2)(uVar1,uVar2,auStack_70);
    uVar2 = FUN_400dc350(param_1);
    uVar4 = FUN_400d4db0(auStack_58,"retries",auStack_70);
    FUN_40183f18(uVar2,uVar4);
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 100);
    uVar2 = FUN_400d4db0(auStack_58," - will retry",auStack_70);
    (*(code *)&LAB_40183f5a_2)(uVar1,uVar2,auStack_70);
    uVar1 = *(undefined1 *)(param_1 + 0x6e);
    uVar2 = FUN_400d4db0(auStack_58,"t_retry",auStack_70);
    (*(code *)&LAB_40183f5a_2)(uVar1,uVar2,auStack_70);
  }
  uVar1 = *(undefined1 *)(param_1 + 0x30);
  uVar2 = FUN_400d4db0(auStack_58,"ng_time",auStack_70);
  FUN_40183f38(uVar1,uVar2,auStack_70);
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x54) + 4);
  uVar2 = FUN_400d4db0(auStack_58,"_active",auStack_70);
  FUN_40183f38(uVar1,uVar2,auStack_70);
  FUN_400f0be8(auStack_34,&DAT_3f42161d);
  FUN_400d5948(auStack_58,auStack_34);
  if (*(int *)(param_1 + 0x1c) != 0) goto LAB_400dce22;
  FUN_40170584();
  FUN_400f0a50(auStack_34);
  while( true ) {
    FUN_400d73a8(auStack_78);
    thunk_FUN_401710d8(param_1);
LAB_400dce22:
    (**(code **)(param_1 + 0x20))(param_1 + 0x14,param_2,auStack_34);
    FUN_400f0a50(auStack_34);
    FUN_400d73a8(auStack_78);
LAB_400dce42:
    param_2 = iStack_24;
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
  }
  return;
}

