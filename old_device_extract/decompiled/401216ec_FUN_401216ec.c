// Function : FUN_401216ec
// Address  : 0x401216ec
// Size     : 181 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401216ec(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_33 [15];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar2 = 0;
  iVar5 = 0;
  do {
    while( true ) {
      memw();
      FUN_401742a8(auStack_33,0xf,"p_ipc.c",iVar5);
      uVar3 = (*(code *)&SUB_4008fcc8)(1);
      *(undefined4 *)(iVar2 + 0x3ffc6d64) = uVar3;
      memw();
      uVar3 = (*(code *)&SUB_4008f990)(1,0,3);
      *(undefined4 *)(iVar2 + 0x3ffc6d54) = uVar3;
      memw();
      uVar3 = (*(code *)&SUB_4008f990)(1,0,3);
      *(undefined4 *)(iVar2 + 0x3ffc6d5c) = uVar3;
      memw();
      iVar4 = (*(code *)&SUB_4009092c)
                        (0x40086934,auStack_33,0x400,iVar5,0x18,iVar2 + 0x3ffc6d6c,iVar5);
      if (iVar4 == 1) break;
      (*(code *)&SUB_40094c54)("ipc/src/esp_ipc.c",0x73,"pc_task","0)");
      iVar5 = 1;
    }
    iVar2 = iVar2 + 4;
    bVar1 = iVar5 != 1;
    iVar5 = 1;
  } while (bVar1);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return;
}

