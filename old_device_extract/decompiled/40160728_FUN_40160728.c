// Function : FUN_40160728
// Address  : 0x40160728
// Size     : 488 bytes


void FUN_40160728(uint *param_1,byte param_2,byte param_3,byte param_4)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  char cVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (((param_3 < param_4) && (param_2 == 0)) || (uVar3 = *param_1, uVar3 == 0)) {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"tryFail",0x529);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (*(byte *)((int)param_1 + 0xb) < DAT_3ffbfff5) {
    *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 0xb) + 1;
    memw();
  }
  if (*(byte *)((int)param_1 + 0xb) < DAT_3ffbfff5) {
    if ((byte)param_1[2] < *(byte *)((int)param_1 + 10)) {
      cVar4 = (byte)param_1[2] + 1;
      memw();
      goto LAB_40160790;
    }
  }
  else {
    cVar4 = *(char *)((int)param_1 + 9);
LAB_40160790:
    *(char *)(param_1 + 2) = cVar4;
    memw();
  }
  *(char *)(*(int *)(uVar3 + 0x2c) + 6) = *(char *)(*(int *)(uVar3 + 0x2c) + 6) + '\x01';
  memw();
  if (param_2 < (param_3 ^ 1)) {
    *(char *)(*(int *)(uVar3 + 0x2c) + 5) = *(char *)(*(int *)(uVar3 + 0x2c) + 5) + '\x01';
    memw();
  }
  if (1 < (byte)(*(char *)((int)param_1 + 0x12) - 1U)) {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"tryFail",0x53c);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_40164da8(*(undefined4 *)(uVar3 + 0x2c));
  if (((iVar1 == 0) && (*(byte *)(*(int *)(uVar3 + 0x2c) + 6) < DAT_3ffbfff5)) &&
     ((iVar1 = FUN_40187d04(uVar3), iVar1 == 0 &&
      (uVar6 = **(uint **)(uVar3 + 0x2c), (uVar6 & 0x10000000) == 0)))) {
    if (param_2 == 0) {
      if (param_3 == 0) {
        if ((uVar6 & 0x600002) == 0) {
          iVar1 = *(int *)(*(int *)(uVar3 + 4) + 4);
          if ((uVar6 & 0x40000) != 0) {
            iVar1 = iVar1 + 4;
          }
          *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 8;
          memw();
          memw();
        }
        else {
          uVar6 = uVar6 & 0x400000;
          while (uVar6 != 0) {
            if ((**(uint **)(uVar3 + 0x2c) & 0x40000) == 0) {
              iVar1 = *(int *)(*(int *)(uVar3 + 4) + 4);
            }
            else {
              iVar1 = *(int *)(*(int *)(uVar3 + 4) + 4) + 4;
            }
            *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 8;
            memw();
            uVar3 = *(uint *)(uVar3 + 0x28);
            uVar6 = uVar3;
          }
        }
      }
      if (param_4 <= param_3) {
        uVar7 = 1;
        goto LAB_401608d5;
      }
    }
    else {
      if (*(char *)((int)param_1 + 0x12) != '\x01') {
        memw();
        FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"tryFail",0x568);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      *(undefined1 *)((int)param_1 + 0x12) = 4;
      memw();
      memw();
      FUN_401604d4(param_1);
    }
  }
  else {
    puVar5 = *(uint **)(uVar3 + 0x2c);
    if ((*puVar5 & 0x400100) == 0x400100) {
      memw();
      iVar1 = FUN_401600f4(uVar3);
      uVar2 = DAT_3ffc000c;
      if (iVar1 != 0) {
        uVar2 = DAT_3ffc000b;
      }
      *(undefined1 *)((int)puVar5 + 5) = uVar2;
      memw();
      *param_1 = 0;
      memw();
      FUN_40160384(param_1,uVar3);
      return;
    }
    *(undefined1 *)((int)param_1 + 0x12) = 6;
    memw();
    if (param_2 != 0) {
      FUN_40160578(param_1);
      return;
    }
    uVar7 = 0;
    if (param_4 <= param_3) {
LAB_401608d5:
      memw();
      FUN_4018804c(param_1,1,uVar7);
      return;
    }
    memw();
  }
  return;
}

