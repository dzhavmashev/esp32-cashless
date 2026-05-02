// Function : FUN_40187dd4
// Address  : 0x40187dd4
// Size     : 441 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40187dd4(int param_1,uint param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  
  param_2 = param_2 & 0xff;
  if ((1 < (byte)((&DAT_3ffc7b2e)[param_2 * 0x24] - 3)) && ((&DAT_3ffc7b2e)[param_2 * 0x24] != '\0')
     ) {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"cTxDone",0x6f8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  piVar5 = (int *)(&DAT_3ffc7b1c + param_2 * 0x24);
  (**(code **)(_DAT_3ffc1a34 + 0xd8))();
  if ((&DAT_3ffc7b2e)[param_2 * 0x24] == '\x04') {
    if (*piVar5 != param_1) {
      memw();
      FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"cTxDone",0x700);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else {
    *piVar5 = param_1;
    if (param_1 == 0) {
      memw();
      FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"cTxDone",0x709);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar7 = **(uint **)(param_1 + 0x2c);
    if ((uVar7 & 0x2102) == 0x2000) {
      **(uint **)(param_1 + 0x2c) = uVar7 | 0x1000;
    }
    memw();
    iVar3 = FUN_401600f4(param_1);
    if (iVar3 != 0) {
      uVar7 = **(uint **)(param_1 + 0x2c);
      if ((uVar7 & 2) == 0) {
        **(uint **)(param_1 + 0x2c) = uVar7 | 0x100;
        **(uint **)(param_1 + 0x2c) = **(uint **)(param_1 + 0x2c) & 0xffffefff;
      }
    }
    puVar6 = *(uint **)(param_1 + 0x2c);
    if ((((*puVar6 & 0x1000) != 0) && ((&DAT_3ffc7b2e)[param_2 * 0x24] == '\x03')) &&
       (DAT_3ffc000a <= *(byte *)((int)puVar6 + 5))) {
      *puVar6 = *puVar6 | 0x100;
      **(uint **)(param_1 + 0x2c) = **(uint **)(param_1 + 0x2c) & 0xffffefff;
      *(undefined1 *)(*(int *)(param_1 + 0x2c) + 7) = *(undefined1 *)(*(int *)(param_1 + 0x2c) + 6);
      memw();
      *(undefined1 *)(*(int *)(param_1 + 0x2c) + 6) = 0;
      memw();
    }
    memw();
    FUN_40160118(piVar5,0);
  }
  iVar3 = param_2 * 0x24;
  if (((uint)*(byte *)(iVar3 + 0x3ffc7b25) << 1 < (uint)*(byte *)(iVar3 + 0x3ffc7b24)) &&
     (iVar4 = FUN_401600f4(param_1), iVar4 == 0)) {
    uVar2 = FUN_40189c00();
    *(ushort *)(iVar3 + 0x3ffc7b22) =
         (short)(1 << 0x20 - ((*(byte *)(iVar3 + 0x3ffc7b25) & 0xf) * -2 + 0x20)) - 1U & uVar2;
    memw();
    memw();
  }
  else {
    uVar2 = FUN_40189c00();
    *(ushort *)(param_2 * 0x24 + 0x3ffc7b22) =
         (short)(1 << 0x20 - (0x20 - (*(byte *)(param_2 * 0x24 + 0x3ffc7b24) & 0x1f))) - 1U & uVar2;
    memw();
  }
  memw();
  FUN_40189b24(piVar5);
  uVar1 = *(undefined1 *)(param_2 * 0x24 + 0x3ffc7b20);
  (&DAT_3ffc7b2e)[param_2 * 0x24] = 1;
  memw();
  memw();
  FUN_40189b7c(uVar1);
  (**(code **)(_DAT_3ffc1a34 + 0xdc))();
  return;
}

