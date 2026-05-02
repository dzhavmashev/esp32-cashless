// Function : FUN_40116a38
// Address  : 0x40116a38
// Size     : 646 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
FUN_40116a38(int param_1,uint *param_2,uint *param_3,byte param_4,byte param_5,byte param_6,
            int param_7,undefined4 param_8,ushort param_9)

{
  undefined2 uVar1;
  short sVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined4 uVar10;
  char *pcVar11;
  uint uStack_3c;
  uint local_24 [9];
  
  uVar4 = (uint)param_9;
  if (*(char *)(param_1 + 0xe) == '\x01') goto LAB_40116a6b;
  pcVar11 = "p_group";
  uVar10 = 0x3b2;
  while( true ) {
    memw();
    (*(code *)&SUB_40094c54)("ef == 1",uVar10," ip_hdr",pcVar11);
LAB_40116a6b:
    if (param_3 == (uint *)0x0) {
      if (*(ushort *)(param_1 + 10) < 0x14) {
        return 0xfe;
      }
      param_3 = local_24;
      local_24[0] = *(uint *)(*(int *)(param_1 + 4) + 0x10);
      memw();
      goto LAB_40116c24;
    }
    if (uVar4 == 0) {
      uStack_3c = 0x14;
      memw();
      uVar8 = 0;
    }
    else {
      if (0x28 < uVar4) {
        return 0xfa;
      }
      uVar8 = uVar4 + 3 & 0xfffc;
      uStack_3c = uVar8 + 0x14 & 0xffff;
      memw();
      iVar5 = FUN_4010ba7c(param_1,uVar8);
      if (iVar5 != 0) {
        return 0xfe;
      }
      memw();
      (*(code *)&SUB_4008b3d0)(*(undefined4 *)(param_1 + 4),param_8,uVar4);
      if (uVar4 < uVar8) {
        (*(code *)&SUB_4008b530)(*(int *)(param_1 + 4) + uVar4,0,uVar8 - uVar4);
      }
      uVar8 = (uint)**(ushort **)(param_1 + 4);
    }
    memw();
    iVar5 = FUN_4010ba7c(param_1,0x14);
    if (iVar5 != 0) {
      return 0xfe;
    }
    pbVar9 = *(byte **)(param_1 + 4);
    if (0x13 < *(ushort *)(param_1 + 10)) break;
    pcVar11 = "4/ip4.c";
    uVar10 = 999;
  }
  pbVar9[8] = param_4;
  pbVar9[9] = param_6;
  memw();
  uVar4 = *param_3;
  pbVar9[0x11] = (byte)(uVar4 >> 8);
  pbVar9[0x13] = (byte)(uVar4 >> 0x18);
  memw();
  *pbVar9 = (byte)(uStack_3c >> 2) | 0x40;
  pbVar9[0x10] = (byte)uVar4;
  pbVar9[1] = param_5;
  memw();
  uVar1 = *(undefined2 *)(param_1 + 8);
  pbVar9[0x12] = (byte)(uVar4 >> 0x10);
  memw();
  memw();
  iVar5 = FUN_40185290(uVar1);
  pbVar9[3] = (byte)((uint)iVar5 >> 8);
  memw();
  pbVar9[2] = (byte)iVar5;
  sVar2 = _DAT_3ffc6488;
  memw();
  pbVar9[6] = 0;
  pbVar9[7] = 0;
  memw();
  memw();
  iVar6 = FUN_40185290(sVar2);
  pbVar9[5] = (byte)((uint)iVar6 >> 8);
  memw();
  _DAT_3ffc6488 = _DAT_3ffc6488 + 1;
  pbVar9[4] = (byte)iVar6;
  memw();
  if (param_2 == (uint *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *param_2;
  }
  pbVar9[0xc] = (byte)uVar7;
  pbVar9[0xd] = (byte)(uVar7 >> 8);
  uVar4 = (uVar7 >> 0x10) +
          (uVar7 & 0xffff) +
          iVar6 + iVar5 + ((uint)param_5 << 8 |
                          (int)((uStack_3c >> 2 & 0xff | 0x40) << 8 | (uint)param_5) >> 8) +
                          ((CONCAT11(param_4,param_6) & 0xff) << 8 |
                          (int)(uint)CONCAT11(param_4,param_6) >> 8) +
                          (uVar4 & 0xffff) + (uVar4 >> 0x10) + uVar8;
  pbVar9[0xe] = (byte)(uVar7 >> 0x10);
  uVar4 = (uVar4 >> 0x10) + (uVar4 & 0xffff);
  uVar4 = ((uVar4 >> 0x10) + uVar4 ^ 0xffffffff) & 0xffff;
  pbVar9[10] = (byte)uVar4;
  pbVar9[0xf] = (byte)(uVar7 >> 0x18);
  pbVar9[0xb] = (byte)(uVar4 >> 8);
  memw();
LAB_40116c24:
  if (*param_3 == *(uint *)(param_7 + 4)) {
    memw();
    uVar3 = FUN_4010b600(param_7,param_1);
  }
  else {
    if ((*(byte *)(param_1 + 0xd) & 4) != 0) {
      FUN_4010b600(param_7,param_1);
    }
    if ((*(ushort *)(param_7 + 0xe0) == 0) ||
       (*(ushort *)(param_1 + 8) <= *(ushort *)(param_7 + 0xe0))) {
      uVar3 = (**(code **)(param_7 + 0xb8))(param_7,param_1,param_3);
    }
    else {
      uVar3 = FUN_40116eac(param_1,param_7,param_3);
    }
  }
  return uVar3;
}

