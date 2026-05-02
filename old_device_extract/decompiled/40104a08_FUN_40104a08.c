// Function : FUN_40104a08
// Address  : 0x40104a08
// Size     : 955 bytes


uint FUN_40104a08(uint param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  char *pcVar13;
  char *pcVar14;
  int in_t0;
  
  if (*(int *)(param_1 + 0x240) == 2) {
    uVar9 = 0x16;
    if (*(int *)(param_1 + 0x1c0) != 0) {
      uVar9 = 0x28;
    }
    iVar8 = *(int *)(param_1 + 0x1e8);
    uVar12 = *(undefined4 *)(param_1 + 0x1ec);
    iVar3 = *(int *)(param_1 + 0x1f0);
    uVar4 = *(undefined4 *)(param_1 + 500);
    if (uVar9 <= param_3) {
      *param_2 = 0x30;
      param_2[2] = 1;
      param_2[3] = 0;
      memw();
      memw();
      iVar11 = FUN_40106368(2,uVar12);
      if (iVar11 != 0) {
        iVar10 = param_1 + 0x300;
        param_2[4] = (char)((uint)iVar11 >> 0x18);
        param_2[5] = (char)((uint)iVar11 >> 0x10);
        param_2[6] = (char)((uint)iVar11 >> 8);
        param_2[7] = (char)iVar11;
        memw();
        if ((*(char *)(param_1 + 0x344) != '\x01') && (iVar3 != 1)) {
          param_1 = 8;
          param_2[1] = 6;
          memw();
          goto LAB_40104a85;
        }
        param_2[8] = 1;
        param_2[9] = 0;
        memw();
        memw();
        iVar1 = FUN_40106368(2,iVar8);
        iVar11 = 0;
        uVar6 = 0;
        if ((iVar1 != 0) && (iVar8 != 1)) {
          param_2[10] = (char)((uint)iVar1 >> 0x18);
          param_2[0xb] = (char)((uint)iVar1 >> 0x10);
          param_2[0xc] = (char)((uint)iVar1 >> 8);
          param_2[0xd] = (char)iVar1;
          param_2[0xe] = 1;
          param_2[0xf] = 0;
          memw();
          if (iVar3 == 1) goto LAB_40104ae6;
          goto LAB_40104ba8;
        }
      }
    }
LAB_40104dc0:
    param_1 = 0xffffffff;
  }
  else {
    if (*(int *)(param_1 + 0x240) == 4) {
      param_1 = 0;
      goto LAB_40104a85;
    }
    iVar11 = *(int *)(param_1 + 0x1e8);
    iVar8 = *(int *)(param_1 + 0x1ec);
    iVar3 = *(int *)(param_1 + 0x1f0);
    if (param_3 < 0x18) goto LAB_40104dc0;
    *param_2 = 0xdd;
    param_2[2] = 0;
    param_2[3] = 0x50;
    param_2[4] = 0xf2;
    param_2[5] = 1;
    param_2[7] = 0;
    param_2[6] = 1;
    memw();
    if (iVar8 == 8) {
      param_2[8] = 0;
      uVar6 = 4;
      param_2[9] = 0x50;
      param_2[10] = 0xf2;
LAB_40104cb8:
      param_2[0xb] = uVar6;
      memw();
      memw();
    }
    else if (iVar8 == 2) {
      param_2[8] = 0;
      param_2[9] = 0x50;
      param_2[10] = 0xf2;
      param_2[0xb] = 2;
    }
    else {
      if (iVar8 == 0x100) {
        param_2[8] = 0;
        uVar6 = 5;
        param_2[9] = 0x50;
        param_2[10] = 0xf2;
        memw();
        memw();
        goto LAB_40104cb8;
      }
      if (iVar8 != 0x80) goto LAB_40104dc0;
      param_2[8] = 0;
      param_2[9] = 0x50;
      param_2[10] = 0xf2;
      param_2[0xb] = 1;
      memw();
      memw();
    }
    param_2[0xc] = 1;
    uVar6 = 0;
    param_2[0xd] = 0;
    memw();
    if (iVar11 == 8) {
      param_2[0xe] = 0;
      param_2[0xf] = 0x50;
      param_2[0x10] = 0xf2;
      uVar6 = 4;
LAB_40104cf2:
      param_2[0x11] = uVar6;
      memw();
      memw();
    }
    else {
      if (iVar11 != 2) {
        if (iVar11 != 1) goto LAB_40104dc0;
        param_2[0xf] = 0x50;
        param_2[0xe] = 0;
        param_2[0x10] = 0xf2;
        memw();
        memw();
        goto LAB_40104cf2;
      }
      param_2[0xe] = 0;
      param_2[0xf] = 0x50;
      param_2[0x10] = 0xf2;
      param_2[0x11] = 2;
    }
    uVar4 = 0xfffffff2;
    param_2[0x12] = 1;
    param_2[0x13] = 0;
    memw();
    if ((iVar3 == 1) || (iVar3 == 2)) {
      param_2[0x14] = 0;
      param_2[0x15] = 0x50;
      param_2[0x16] = 0xf2;
      param_2[0x17] = (char)iVar3;
    }
    else {
      if (iVar3 != 0x10) goto LAB_40104dc0;
      param_2[0x15] = 0x50;
      param_2[0x14] = 0;
      param_2[0x16] = 0xf2;
      param_2[0x17] = 0;
      memw();
      memw();
    }
    iVar3 = 0x16;
    param_1 = 0x18;
    param_2[1] = 0x16;
    memw();
    if (param_3 < 0x18) {
      uVar12 = 0x72;
      pcVar14 = "pa_ie.c";
      pcVar13 = "_ie_len";
      memw();
      iVar11 = in_t0;
      while( true ) {
        memw();
        (*(code *)&SUB_40094c54)("sn_supp/wpa_ie.c",uVar12,pcVar13,pcVar14);
        iVar10 = iVar11;
        in_t0 = iVar11;
LAB_40104ba8:
        uVar6 = (undefined1)iVar11;
        if (iVar3 == 2) {
LAB_40104ae6:
          param_2[0x11] = 0xf;
          param_2[0x10] = uVar6;
          param_2[0x12] = 0xac;
          param_2[0x13] = (char)iVar3;
          memw();
          iVar11 = in_t0;
        }
        else {
          if (iVar3 == 0x80) {
            param_2[0x11] = 0xf;
            param_2[0x12] = 0xac;
            uVar5 = 5;
            param_2[0x10] = uVar6;
          }
          else if (iVar3 == 0x100) {
            param_2[0x11] = 0xf;
            param_2[0x12] = 0xac;
            uVar5 = 6;
            param_2[0x10] = uVar6;
            memw();
            memw();
          }
          else if (iVar3 == 0x400) {
            param_2[0x11] = 0xf;
            param_2[0x12] = 0xac;
            uVar5 = 8;
            param_2[0x10] = uVar6;
            memw();
            memw();
          }
          else if (iVar3 == 0x20000) {
            param_2[0x11] = 0xf;
            param_2[0x12] = 0xac;
            uVar5 = 0xc;
            param_2[0x10] = uVar6;
            memw();
            memw();
          }
          else {
            if (iVar3 != 0x10000) goto LAB_40104dc0;
            param_2[0x11] = 0xf;
            param_2[0x12] = 0xac;
            uVar5 = 0xb;
            param_2[0x10] = uVar6;
            memw();
            memw();
          }
          param_2[0x13] = uVar5;
          memw();
          memw();
          iVar11 = in_t0;
        }
        uVar7 = 0;
        if ((*(char *)(iVar10 + 0x45) != '\0') &&
           ((*(char *)(iVar10 + 0x46) != '\0' || (uVar7 = 0x80, iVar3 == 0x400)))) {
          uVar7 = 0xc0;
        }
        if (*(char *)(iVar10 + 0x48) != '\0') {
          uVar7 = uVar7 | 0x400;
        }
        if (*(char *)(iVar10 + 0x49) != '\0') {
          uVar7 = uVar7 | 0x800;
        }
        param_2[0x15] = (char)(uVar7 >> 8);
        param_2[0x14] = (char)uVar7;
        memw();
        if (*(int *)(param_1 + 0x1c0) == 0) {
          puVar2 = param_2 + 0x16;
        }
        else {
          param_2[0x16] = 1;
          param_2[0x17] = 0;
          memw();
          puVar2 = param_2 + 0x28;
          memw();
          (*(code *)&SUB_4008b3d0)(param_2 + 0x18,*(int *)(param_1 + 0x1c0) + 4,0x10);
        }
        memw();
        iVar3 = FUN_40105ca0(uVar4);
        if (iVar3 != 0) {
          if (*(int *)(param_1 + 0x1c0) == 0) {
            puVar2[1] = 0;
            *puVar2 = 0;
            memw();
            puVar2 = puVar2 + 2;
          }
          memw();
          uVar12 = FUN_40106368(2,uVar4);
          *puVar2 = (char)((uint)uVar12 >> 0x18);
          puVar2[1] = (char)((uint)uVar12 >> 0x10);
          puVar2[2] = (char)((uint)uVar12 >> 8);
          puVar2[3] = (char)uVar12;
          puVar2 = puVar2 + 4;
        }
        param_1 = (int)puVar2 - (int)param_2;
        iVar3 = param_1 - 2;
        param_2[1] = (char)iVar3;
        memw();
        if (param_1 <= param_3) break;
        uVar12 = 0x106;
        pcVar14 = "pansion";
        pcVar13 = "_ie_wpa";
      }
    }
  }
LAB_40104a85:
  memw();
  return param_1;
}

