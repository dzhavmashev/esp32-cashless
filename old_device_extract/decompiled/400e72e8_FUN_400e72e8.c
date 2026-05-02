// Function : FUN_400e72e8
// Address  : 0x400e72e8
// Size     : 811 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e72e8(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  int iStack_b4;
  undefined1 uStack_b0;
  undefined1 auStack_a8 [8];
  undefined1 uStack_a0;
  undefined1 auStack_94 [16];
  undefined1 auStack_84 [16];
  undefined1 *apuStack_74 [9];
  undefined4 uStack_50;
  undefined1 auStack_4c [40];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iStack_c0 = func_0x40094d68(0x200);
  iStack_b8 = 0;
  if (iStack_c0 != 0) {
    iStack_b8 = iStack_c0 + 0x200;
  }
  uStack_b0 = 0;
  uStack_a0 = 0;
  iStack_bc = iStack_c0;
  iStack_b4 = iStack_b8;
  puVar1 = (undefined4 *)FUN_400d4db0(auStack_a8,"offline status",&iStack_c0);
  if (puVar1 != (undefined4 *)0x0) {
    *(byte *)(puVar1 + 2) = *(byte *)(puVar1 + 2) & 0x80 | 4;
    *puVar1 = "ssfully";
    puVar1[1] = 6;
  }
  uVar3 = *param_2;
  puVar1 = (undefined4 *)FUN_400d4db0(auStack_a8,"_status",&iStack_c0);
  if (puVar1 != (undefined4 *)0x0) {
    *(byte *)(puVar1 + 2) = *(byte *)(puVar1 + 2) & 0x80 | 8;
    *puVar1 = uVar3;
    puVar1[1] = 0;
  }
  uVar3 = param_2[1];
  puVar1 = (undefined4 *)FUN_400d4db0(auStack_a8,"ime",&iStack_c0);
  if (puVar1 != (undefined4 *)0x0) {
    *(byte *)(puVar1 + 2) = *(byte *)(puVar1 + 2) & 0x80 | 8;
    *puVar1 = uVar3;
    puVar1[1] = 0;
  }
  iVar4 = param_2[2];
  piVar2 = (int *)FUN_400d4db0(auStack_a8,"ip",&iStack_c0);
  if (piVar2 != (int *)0x0) {
    *piVar2 = iVar4;
    *(byte *)(piVar2 + 2) = *(byte *)(piVar2 + 2) & 0x80 | 10;
    piVar2[1] = iVar4 >> 0x1f;
  }
  uVar3 = FUN_400d4db0(auStack_a8,"trieved",&iStack_c0);
  FUN_40183db8(param_2 + 3,uVar3,&iStack_c0);
  FUN_400e6d7c(auStack_94,0x3ffc4d78);
  uVar3 = FUN_400d4db0(auStack_a8,"trieved",&iStack_c0);
  FUN_40183db8(auStack_94,uVar3,&iStack_c0);
  FUN_400f0a50(auStack_94);
  iVar4 = param_1[2];
  piVar2 = (int *)FUN_400d4db0(auStack_a8,"er: %s\n",&iStack_c0);
  if (piVar2 != (int *)0x0) {
    *(byte *)(piVar2 + 2) = *(byte *)(piVar2 + 2) & 0x80 | 8;
    *piVar2 = iVar4;
    piVar2[1] = 0;
  }
  uVar3 = FUN_400efe5c(0x3ffc53f4);
  puVar1 = (undefined4 *)FUN_400d4db0(auStack_a8,"",&iStack_c0);
  if (puVar1 != (undefined4 *)0x0) {
    *(byte *)(puVar1 + 2) = *(byte *)(puVar1 + 2) & 0x80 | 8;
    *puVar1 = uVar3;
    puVar1[1] = 0;
  }
  uVar3 = func_0x400efe34(0x3ffc53f4);
  puVar1 = (undefined4 *)FUN_400d4db0(auStack_a8,"t_count",&iStack_c0);
  if (puVar1 != (undefined4 *)0x0) {
    *(byte *)(puVar1 + 2) = *(byte *)(puVar1 + 2) & 0x80 | 8;
    *puVar1 = uVar3;
    puVar1[1] = 0;
  }
  iVar4 = FUN_400f11c0(param_2 + 3,"g state");
  if ((iVar4 != 0) && (iVar4 = FUN_400e966c(&DAT_3ffc516c), iVar4 != 0)) {
    iVar4 = FUN_400e81ac(&DAT_3ffc516c);
    piVar2 = (int *)FUN_400d4db0(auStack_a8,"ap_size",&iStack_c0);
    if (piVar2 != (int *)0x0) {
      *piVar2 = iVar4;
      *(byte *)(piVar2 + 2) = *(byte *)(piVar2 + 2) & 0x80 | 10;
      piVar2[1] = iVar4 >> 0x1f;
    }
    FUN_400e9734(auStack_4c,&DAT_3ffc516c);
    uVar3 = FUN_400d4db0(auStack_a8,"channel",&iStack_c0);
    FUN_40183db8(auStack_4c,uVar3,&iStack_c0);
    FUN_400f0a50(auStack_4c);
  }
  FUN_400f0be8(auStack_84,&DAT_3f42161d);
  uStack_50 = 0;
  apuStack_74[0] = auStack_84;
  func_0x4008b3d8(auStack_4c,apuStack_74,0x28);
  FUN_400d58a8(auStack_a8,auStack_4c);
  FUN_400d3f28(auStack_4c);
  FUN_400d3f28(apuStack_74);
  iVar4 = *param_1;
  FUN_400f0be8(auStack_4c,"kipping heartbeat");
  while( true ) {
    FUN_400db714(iVar4,auStack_4c,auStack_84,0);
    FUN_400f0a50(auStack_4c);
    FUN_400f0a50(auStack_84);
    if (iStack_c0 != 0) {
      func_0x40094d88();
    }
    iVar4 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    FUN_400f0a50(auStack_4c);
    FUN_400f0a50(auStack_84);
    if (iStack_c0 != 0) {
      func_0x40094d88();
    }
    thunk_FUN_401710d8(iVar4);
  }
  return;
}

