// Function : FUN_40118a08
// Address  : 0x40118a08
// Size     : 366 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40118a08(int param_1,undefined1 *param_2,byte param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  
  uVar4 = *(byte *)(param_1 + 0xea) + 2;
  iVar6 = (uint)((uVar4 & 7) != 0) + ((int)uVar4 >> 3);
  iVar3 = FUN_4010bbc4(0x36,iVar6 * 8 + 0x18,0x280);
  if (iVar3 != 0) {
    puVar5 = *(undefined1 **)(iVar3 + 4);
    *puVar5 = 0x88;
    puVar5[1] = 0;
    puVar5[4] = param_3 & 0xf0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    puVar5[7] = 0;
    memw();
    puVar5[8] = *param_2;
    memw();
    puVar5[9] = param_2[1];
    memw();
    puVar5[10] = param_2[2];
    memw();
    puVar5[0xb] = param_2[3];
    memw();
    puVar5[0xc] = param_2[4];
    memw();
    puVar5[0xd] = param_2[5];
    memw();
    puVar5[0xe] = param_2[6];
    memw();
    puVar5[0xf] = param_2[7];
    memw();
    puVar5[0x10] = param_2[8];
    memw();
    puVar5[0x11] = param_2[9];
    memw();
    puVar5[0x12] = param_2[10];
    memw();
    uVar1 = param_2[0xb];
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[0x13] = uVar1;
    memw();
    puVar5[0x14] = param_2[0xc];
    memw();
    puVar5[0x15] = param_2[0xd];
    memw();
    puVar5[0x16] = param_2[0xe];
    memw();
    puVar5[0x17] = param_2[0xf];
    puVar5[0x18] = 2;
    puVar5[0x19] = (char)iVar6;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(puVar5 + 0x1a,param_1 + 0xe4,*(undefined1 *)(param_1 + 0xea));
    puVar7 = &DAT_3ffc83cc;
    if ((param_3 & 2) != 0) {
      puVar7 = &DAT_3ffc64b4;
      _DAT_3ffc64b4 = 0x2ff;
      _DAT_3ffc64c0 = 0x1000000;
      DAT_3ffc64c4 = *(char *)(param_1 + 0xee) + '\x01';
      _DAT_3ffc64b8 = 0;
      _DAT_3ffc64bc = 0;
      memw();
    }
    memw();
    uVar2 = FUN_4011dbec(iVar3,0x3a,*(undefined2 *)(iVar3 + 10),param_2,puVar7);
    puVar5[2] = (char)uVar2;
    memw();
    puVar5[3] = (char)((ushort)uVar2 >> 8);
    memw();
    memw();
    FUN_40117f9c(iVar3,param_2,puVar7,0xff,0,0x3a,param_1);
    FUN_4010bb10(iVar3);
  }
  return;
}

