// Function : FUN_40188980
// Address  : 0x40188980
// Size     : 470 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40188980(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  
  iVar2 = FUN_4018ba60(*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x13 & 1);
  if (iVar2 == 0) {
    FUN_40147fe4(6,0x40,2,0x3f43707d,*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x13 & 1);
  }
  else {
    uVar7 = *(uint *)(*(int *)(param_1 + 0x2c) + 4);
    uVar5 = 4;
    uVar8 = uVar7 & 0xf;
    if (uVar8 < 8) {
      if ((uVar8 == 0) || (uVar8 == 3)) {
        uVar5 = 2;
      }
      else {
        uVar5 = 3;
        if ((2 < uVar8) && (uVar5 = 1, 5 < uVar8)) {
          uVar5 = 0;
        }
      }
    }
    if (uVar5 != (uVar7 >> 4 & 0xf)) {
      FUN_40147fe4(6,0x800,1,"","s_func_app.c",0x345);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar2 = (uVar5 + 0xe) * 8;
    *(int *)(iVar2 + 0x3ffc7c60) = *(int *)(iVar2 + 0x3ffc7c60) + 1;
    memw();
    FUN_401882e4(param_1);
    iVar2 = FUN_40188810(param_1);
    if (iVar2 != 1) {
      FUN_40189844(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x2c));
      FUN_40188920(param_1);
      iVar2 = FUN_40188694(param_1);
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x2c);
        if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
          memw();
          iVar3 = _DAT_3ff73c00 + _DAT_3ffc1a30;
        }
        else {
          iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
        }
        *(int *)(iVar2 + 0x18) = iVar3;
        piVar6 = *(int **)(_DAT_3ffc0034 +
                           (*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x14 & 0xf) * 0x30 + 0x24)
        ;
        *(undefined4 *)(param_1 + 0x28) = 0;
        *piVar6 = param_1;
        *(int *)(_DAT_3ffc0034 + (*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x14 & 0xf) * 0x30 +
                0x24) = param_1 + 0x28;
        if ((param_2 == '\0') ||
           (iVar2 = FUN_401600d4(*(uint *)(*(int *)(param_1 + 0x2c) + 4) >> 4 & 0xf), iVar2 == 0)) {
LAB_40188a92:
          memw();
          return 0;
        }
        uVar4 = (*(code *)&SUB_40087bcc)(*(uint *)(*(int *)(param_1 + 0x2c) + 4) >> 4 & 0xf,0);
      }
      else {
        if (iVar2 != 1) {
          if (iVar2 != 2) goto LAB_40188a92;
          FUN_40147fe4(6,0x40,2,0x3f437073);
          goto LAB_40188b49;
        }
        iVar2 = *(int *)(param_1 + 0x2c);
        if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
          memw();
          iVar3 = _DAT_3ff73c00 + _DAT_3ffc1a30;
        }
        else {
          iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
        }
        *(int *)(iVar2 + 0x18) = iVar3;
        uVar4 = 0;
        piVar6 = *(int **)(((*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x13 & 1) + 0x66) * 8 +
                           _DAT_3ffc0034 + 8);
        *(undefined4 *)(param_1 + 0x28) = 0;
        *piVar6 = param_1;
        *(int *)(((*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x13 & 1) + 0x66) * 8 +
                 _DAT_3ffc0034 + 8) = param_1 + 0x28;
      }
      memw();
      return uVar4;
    }
  }
LAB_40188b49:
  cVar1 = *(char *)(param_1 + 0x1a);
  FUN_4018a7b8(param_1);
  if (cVar1 == '\x01') {
    FUN_401882d0();
  }
  return 1;
}

