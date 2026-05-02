// Function : FUN_40117c04
// Address  : 0x40117c04
// Size     : 916 bytes


undefined1
FUN_40117c04(int param_1,char *param_2,uint *param_3,undefined1 param_4,uint param_5,
            undefined1 param_6,int param_7)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  int iVar6;
  uint *puVar7;
  undefined1 *puVar8;
  uint *puVar9;
  uint uVar10;
  undefined4 uVar11;
  char *pcVar12;
  int in_t0;
  uint local_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  char cStack_24;
  
  if (*(char *)(param_1 + 0xe) == '\x01') goto LAB_40117c2b;
  pcVar12 = "p_group";
  uVar11 = 0x4a5;
  param_7 = in_t0;
  while( true ) {
    param_6 = 0x7e;
    (*(code *)&SUB_40094c54)("esponse",uVar11,"ip6_hdr",pcVar12);
    in_t0 = param_7;
LAB_40117c2b:
    if (param_3 == (uint *)0x0) {
      iVar6 = *(int *)(param_1 + 4);
      local_34 = *(uint *)(iVar6 + 0x18);
      uStack_30 = *(uint *)(iVar6 + 0x1c);
      uStack_2c = *(uint *)(iVar6 + 0x20);
      uStack_28 = *(uint *)(iVar6 + 0x24);
      if (((local_34 & 0xc0ff) == 0x80fe) ||
         (cStack_24 = '\0', ((local_34 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
        cStack_24 = *(char *)(param_7 + 0xee) + '\x01';
      }
      memw();
      param_3 = &local_34;
      memw();
      goto LAB_40117e2d;
    }
    if ((char)param_3[4] == '\0') {
      uVar10 = *param_3;
      if (((uVar10 & 0xc0ff) == 0x80fe) || (((uVar10 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
        uStack_30 = param_3[1];
        uStack_2c = param_3[2];
        uStack_28 = param_3[3];
        if (((uVar10 & 0xc0ff) == 0x80fe) ||
           (cStack_24 = '\0', ((uVar10 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
          cStack_24 = *(char *)(param_7 + 0xee) + '\x01';
        }
        param_3 = &local_34;
        memw();
        local_34 = uVar10;
      }
    }
    memw();
    iVar6 = FUN_4010ba7c(param_1,0x28);
    if (iVar6 != 0) {
      return 0xfe;
    }
    puVar8 = *(undefined1 **)(param_1 + 4);
    if (0x27 < *(ushort *)(param_1 + 10)) break;
    pcVar12 = "6/ip6.c";
    uVar11 = 0x4c0;
    param_7 = in_t0;
  }
  puVar8[6] = param_6;
  puVar8[7] = param_4;
  memw();
  puVar8[0x18] = (char)*param_3;
  memw();
  puVar8[0x19] = *(undefined1 *)((int)param_3 + 1);
  memw();
  puVar8[0x1a] = *(undefined1 *)((int)param_3 + 2);
  memw();
  puVar8[0x1b] = *(undefined1 *)((int)param_3 + 3);
  memw();
  puVar8[0x1c] = (char)param_3[1];
  memw();
  puVar8[0x1d] = *(undefined1 *)((int)param_3 + 5);
  memw();
  puVar8[0x1e] = *(undefined1 *)((int)param_3 + 6);
  memw();
  puVar8[0x1f] = *(undefined1 *)((int)param_3 + 7);
  memw();
  puVar8[0x20] = (char)param_3[2];
  memw();
  puVar8[0x21] = *(undefined1 *)((int)param_3 + 9);
  memw();
  puVar8[0x22] = *(undefined1 *)((int)param_3 + 10);
  memw();
  puVar8[0x23] = *(undefined1 *)((int)param_3 + 0xb);
  memw();
  puVar8[0x24] = (char)param_3[3];
  memw();
  puVar8[0x25] = *(undefined1 *)((int)param_3 + 0xd);
  memw();
  puVar8[0x26] = *(undefined1 *)((int)param_3 + 0xe);
  memw();
  puVar8[0x27] = *(undefined1 *)((int)param_3 + 0xf);
  memw();
  memw();
  uVar11 = FUN_40109eec((param_5 & 0xff) << 0x14 | 0x60000000);
  *puVar8 = (char)uVar11;
  puVar8[1] = (char)((uint)uVar11 >> 8);
  puVar8[3] = (char)((uint)uVar11 >> 0x18);
  memw();
  sVar2 = *(short *)(param_1 + 8);
  puVar8[2] = (char)((uint)uVar11 >> 0x10);
  memw();
  memw();
  uVar5 = FUN_40185290(sVar2 + -0x28);
  puVar8[4] = (char)uVar5;
  puVar8[5] = (char)((ushort)uVar5 >> 8);
  memw();
  if (param_2 == (char *)0x0) {
    param_2 = "_if_src";
  }
  puVar8[8] = *param_2;
  memw();
  puVar8[9] = param_2[1];
  memw();
  puVar8[10] = param_2[2];
  memw();
  puVar8[0xb] = param_2[3];
  memw();
  puVar8[0xc] = param_2[4];
  memw();
  puVar8[0xd] = param_2[5];
  memw();
  puVar8[0xe] = param_2[6];
  memw();
  puVar8[0xf] = param_2[7];
  memw();
  puVar8[0x10] = param_2[8];
  memw();
  puVar8[0x11] = param_2[9];
  memw();
  puVar8[0x12] = param_2[10];
  memw();
  puVar8[0x13] = param_2[0xb];
  memw();
  puVar8[0x14] = param_2[0xc];
  memw();
  puVar8[0x15] = param_2[0xd];
  memw();
  cVar1 = param_2[0xf];
  puVar8[0x16] = param_2[0xe];
  puVar8[0x17] = cVar1;
  memw();
LAB_40117e2d:
  puVar7 = (uint *)(param_7 + 0x4c);
  puVar9 = (uint *)(param_7 + 0x94);
  while (((((*puVar9 & 0x10) == 0 || (*param_3 != *puVar7)) || (param_3[1] != puVar7[1])) ||
         (((param_3[2] != puVar7[2] || (param_3[3] != puVar7[3])) ||
          ((byte)param_3[4] != (byte)puVar7[4]))))) {
    puVar7 = puVar7 + 6;
    puVar9 = (uint *)((int)puVar9 + 1);
    if ((uint *)(param_7 + 0x94) == puVar7) {
      if ((*(byte *)(param_1 + 0xd) & 4) != 0) {
        memw();
        FUN_4010b600(param_7,param_1);
      }
      if (*(short *)(param_7 + 0xe2) != 0) {
        uVar3 = *(ushort *)(param_1 + 8);
        memw();
        uVar10 = FUN_4011a800(param_3,param_7);
        if (uVar10 < uVar3) {
          uVar4 = FUN_401181c4(param_1,param_7,param_3);
          return uVar4;
        }
      }
      uVar4 = (**(code **)(param_7 + 0xc0))(param_7,param_1,param_3);
      return uVar4;
    }
  }
  memw();
  uVar4 = FUN_4010b600(param_7,param_1);
  return uVar4;
}

