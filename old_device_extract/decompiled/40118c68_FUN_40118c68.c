// Function : FUN_40118c68
// Address  : 0x40118c68
// Size     : 399 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40118c68(int param_1,undefined1 *param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0;
  pcVar5 = "_if_src";
  if (((param_3 & 4) == 0) &&
     (uVar4 = *(byte *)(param_1 + 0x94) & 0x10, (*(byte *)(param_1 + 0x94) & 0x10) != 0)) {
    pcVar5 = (char *)(param_1 + 0x4c);
    uVar4 = *(byte *)(param_1 + 0xea) + 9 >> 3;
  }
  memw();
  iVar2 = FUN_4010bbc4(0x36,uVar4 * 8 + 0x18,0x280);
  if (iVar2 != 0) {
    puVar3 = *(undefined1 **)(iVar2 + 4);
    *puVar3 = 0x87;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    memw();
    puVar3[8] = *param_2;
    memw();
    puVar3[9] = param_2[1];
    memw();
    puVar3[10] = param_2[2];
    memw();
    puVar3[0xb] = param_2[3];
    memw();
    puVar3[0xc] = param_2[4];
    memw();
    puVar3[0xd] = param_2[5];
    memw();
    puVar3[0xe] = param_2[6];
    memw();
    puVar3[0xf] = param_2[7];
    memw();
    puVar3[0x10] = param_2[8];
    memw();
    puVar3[0x11] = param_2[9];
    memw();
    puVar3[0x12] = param_2[10];
    memw();
    puVar3[0x13] = param_2[0xb];
    memw();
    puVar3[0x14] = param_2[0xc];
    memw();
    puVar3[0x15] = param_2[0xd];
    memw();
    puVar3[0x16] = param_2[0xe];
    memw();
    puVar3[0x17] = param_2[0xf];
    memw();
    if (uVar4 != 0) {
      puVar3[0x18] = 1;
      puVar3[0x19] = (char)uVar4;
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)(puVar3 + 0x1a,param_1 + 0xe4,*(undefined1 *)(param_1 + 0xea));
    }
    if ((param_3 & 1) != 0) {
      _DAT_3ffc64b4 = 0x2ff;
      _DAT_3ffc64b8 = 0;
      _DAT_3ffc64bc = 0x1000000;
      _DAT_3ffc64c0 = *(uint *)(param_2 + 0xc) | 0xff;
      DAT_3ffc64c4 = *(char *)(param_1 + 0xee) + '\x01';
      memw();
      param_2 = &DAT_3ffc64b4;
    }
    memw();
    uVar1 = FUN_4011dbec(iVar2,0x3a,*(undefined2 *)(iVar2 + 10),pcVar5,param_2);
    puVar3[2] = (char)uVar1;
    memw();
    puVar3[3] = (char)((ushort)uVar1 >> 8);
    memw();
    if (pcVar5 == "_if_src") {
      pcVar5 = (char *)0x0;
    }
    memw();
    FUN_40117f9c(iVar2,pcVar5,param_2,0xff,0,0x3a,param_1);
    FUN_4010bb10(iVar2);
  }
  return;
}

