// Function : FUN_400e3c9c
// Address  : 0x400e3c9c
// Size     : 498 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e3c9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 ****ppppuVar4;
  undefined1 *puStack_a8;
  char *pcStack_a4;
  undefined1 auStack_a0 [8];
  undefined1 auStack_98 [44];
  undefined4 ***local_6c [3];
  byte bStack_5d;
  undefined1 auStack_5c [16];
  undefined1 auStack_4c [16];
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400d7378(auStack_a0,0x800,0);
  iVar1 = FUN_400d54e4(auStack_98,param_3);
  if (iVar1 == 0) {
    pcStack_a4 = "Unknown command";
    puStack_a8 = auStack_98;
    uVar2 = FUN_400e073c(&puStack_a8,&DAT_3f42161d);
    FUN_400f0be8(local_6c,uVar2);
    pcStack_a4 = "command_id";
    puStack_a8 = auStack_98;
    uVar2 = FUN_400e073c(&puStack_a8,&DAT_3f42161d);
    FUN_400f0be8(auStack_5c,uVar2);
    iVar1 = (*(code *)&LAB_40183a7b_1)(local_6c);
    if (iVar1 == 0) {
      FUN_400f0780(0x3ffc5490," failed");
    }
    else {
      ppppuVar4 = local_6c;
      if ((bStack_5d & 0x80) == 0) {
        ppppuVar4 = (undefined4 ****)local_6c[0];
      }
      FUN_400f06a4(0x3ffc5490,"d field",ppppuVar4);
      iVar1 = FUN_400e03e0(*(undefined4 *)(param_1 + 0x14),param_1 + 0x10,local_6c);
      if ((param_1 + 0x10 == iVar1) || (iVar3 = FUN_400f1218(local_6c,iVar1 + 0x10), iVar3 != 0)) {
        FUN_400f0be8(&uStack_3c,"command");
        uVar2 = FUN_400f10c0(&uStack_3c,local_6c);
        FUN_400f0768(0x3ffc5490,uVar2);
        FUN_400f0a50(&uStack_3c);
        FUN_400f0be8(auStack_4c,"MD: %s\n");
        uStack_3c = 1;
        FUN_400f0d4c(auStack_38,auStack_4c);
        uStack_28 = 0;
        FUN_400f0a50(auStack_4c);
        FUN_400e3a44(param_1,auStack_5c,local_6c,&uStack_3c);
      }
      else {
        if (*(int *)(iVar1 + 0x28) == 0) {
          FUN_40170584();
          goto LAB_400e3e5c;
        }
        (**(code **)(iVar1 + 0x2c))(&uStack_3c,iVar1 + 0x20,auStack_98);
        FUN_400e3a44(param_1,auStack_5c,local_6c,&uStack_3c);
      }
      FUN_400e0700(&uStack_3c);
    }
    FUN_400f0a50(auStack_5c);
    FUN_400f0a50(local_6c);
  }
  else {
    FUN_400f0780(0x3ffc5490,"esponse");
  }
  FUN_400d73a8(auStack_a0);
  param_1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return;
  }
  func_0x40082ecc();
  FUN_400e0700(&uStack_3c);
LAB_400e3e5c:
  do {
    FUN_400f0a50(auStack_5c);
    FUN_400f0a50(local_6c);
    FUN_400d73a8(auStack_a0);
    thunk_FUN_401710d8(param_1);
    FUN_400f0a50(auStack_4c);
  } while( true );
}

