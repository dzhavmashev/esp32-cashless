// Function : FUN_400e6d7c
// Address  : 0x400e6d7c
// Size     : 374 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e6d7c(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 auStack_1f0 [112];
  undefined1 auStack_180 [232];
  undefined1 auStack_98 [16];
  undefined1 auStack_88 [100];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar4 = param_2 + 0x38;
  iVar1 = FUN_400da468(iVar4);
  if (iVar1 != 0) goto LAB_400e6dbd;
  FUN_400f0d4c(param_1,iVar4);
  do {
    while( true ) {
      iVar4 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400e6dbd:
      iVar1 = FUN_400e6a84(param_2);
      if (iVar1 != 0) break;
      FUN_400f0780(0x3ffc5490,"iate CA");
LAB_400e6dd6:
      FUN_400f0be8(param_1,&DAT_3f42161d);
    }
    FUN_4014471c(auStack_1f0);
    iVar1 = param_2 + 8;
    if ((*(byte *)(param_2 + 0x17) & 0x80) == 0) {
      iVar1 = *(int *)(param_2 + 8);
    }
    iVar2 = (*(code *)&LAB_40183a7b_1)();
    iVar1 = FUN_4014517c(auStack_1f0,iVar1,iVar2 + 1);
    if (iVar1 != 0) {
      FUN_40138b60(iVar1,auStack_88,100);
      FUN_400f06a4(0x3ffc5490,"raction",auStack_88);
      FUN_40144730(auStack_1f0);
      goto LAB_400e6dd6;
    }
    FUN_400f0be8(auStack_98,&DAT_3f42161d);
    puVar5 = auStack_180;
    do {
      if ((((*(int *)(puVar5 + 4) == 3) && (pcVar3 = *(char **)(puVar5 + 8), *pcVar3 == 'U')) &&
          (pcVar3[1] == '\x04')) && (pcVar3[2] == '\x03')) {
        FUN_400f0c04(auStack_88,*(undefined4 *)(puVar5 + 0x14),*(undefined4 *)(puVar5 + 0x10));
        FUN_400f0d60(auStack_98,auStack_88);
        FUN_400f0a50(auStack_88);
        break;
      }
      puVar5 = *(undefined1 **)(puVar5 + 0x18);
    } while (puVar5 != (undefined1 *)0x0);
    FUN_40144730(auStack_1f0);
    iVar1 = FUN_400da468(auStack_98);
    if (iVar1 == 0) {
      FUN_400f0d18(iVar4,auStack_98);
    }
    else {
      FUN_400f0780(0x3ffc5490,"te: %s\n");
    }
    FUN_400f0d4c(param_1,iVar4);
    FUN_400f0a50(auStack_98);
  } while( true );
}

