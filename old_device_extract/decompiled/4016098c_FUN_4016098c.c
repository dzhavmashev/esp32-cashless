// Function : FUN_4016098c
// Address  : 0x4016098c
// Size     : 368 bytes


void FUN_4016098c(uint *param_1,char param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  undefined4 uVar5;
  
  uVar2 = 0;
  if (param_3 == '\0') {
    uVar2 = *param_1;
  }
  if ((byte)param_1[3] < DAT_3ffbfff4) {
    *(byte *)(param_1 + 3) = (byte)param_1[3] + 1;
    memw();
  }
  if ((byte)param_1[3] < DAT_3ffbfff4) {
    if ((byte)param_1[2] < *(byte *)((int)param_1 + 10)) {
      cVar4 = (byte)param_1[2] + 1;
      memw();
      goto LAB_401609cd;
    }
  }
  else {
    cVar4 = *(char *)((int)param_1 + 9);
LAB_401609cd:
    *(char *)(param_1 + 2) = cVar4;
    memw();
  }
  *(char *)(*(int *)(uVar2 + 0x2c) + 7) = *(char *)(*(int *)(uVar2 + 0x2c) + 7) + '\x01';
  memw();
  if (param_2 == '\0') {
    *(char *)(*(int *)(uVar2 + 0x2c) + 5) = *(char *)(*(int *)(uVar2 + 0x2c) + 5) + '\x01';
    memw();
  }
  if (1 < (byte)(*(char *)((int)param_1 + 0x12) - 1U)) {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"Timeout",0x5c9);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_40164da8(*(undefined4 *)(uVar2 + 0x2c));
  if (((iVar1 == 0) && (*(byte *)(*(int *)(uVar2 + 0x2c) + 7) < DAT_3ffbfff4)) &&
     (iVar1 = FUN_40187d04(uVar2), iVar1 == 0)) {
    if (param_2 == '\0') {
      uVar3 = **(uint **)(uVar2 + 0x2c);
      if ((uVar3 & 0x400002) == 0) {
        iVar1 = *(int *)(*(int *)(uVar2 + 4) + 4);
        if ((uVar3 & 0x40000) != 0) {
          iVar1 = iVar1 + 4;
        }
        *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 8;
        memw();
        memw();
      }
      else {
        uVar3 = uVar3 & 0x400000;
        while (uVar3 != 0) {
          iVar1 = *(int *)(*(int *)(uVar2 + 4) + 4);
          if ((**(uint **)(uVar2 + 0x2c) & 0x40000) != 0) {
            iVar1 = iVar1 + 4;
          }
          *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 8;
          memw();
          uVar2 = *(uint *)(uVar2 + 0x28);
          uVar3 = uVar2;
        }
      }
      if (param_3 == '\0') {
        uVar5 = 1;
        goto LAB_40160ab9;
      }
    }
    else {
      if (*(char *)((int)param_1 + 0x12) != '\x01') {
        memw();
        FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"Timeout",0x5e7);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      *(undefined1 *)((int)param_1 + 0x12) = 4;
      memw();
      memw();
      FUN_401604d4(param_1,0);
    }
  }
  else {
    *(undefined1 *)((int)param_1 + 0x12) = 6;
    memw();
    if (param_2 != '\0') {
      memw();
      FUN_40160578(param_1);
      return;
    }
    uVar5 = 0;
    if (param_3 == '\0') {
LAB_40160ab9:
      memw();
      FUN_4018804c(param_1,1,uVar5);
      return;
    }
  }
  return;
}

