// Function : FUN_4011e74c
// Address  : 0x4011e74c
// Size     : 1009 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_4011e74c(uint param_1,uint param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 *param_7)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  char *pcVar12;
  uint *in_t0;
  undefined1 in_PRID;
  int iStack_4c;
  uint uStack_48;
  int iStack_44;
  uint local_2c [11];
  
  if (((((param_2 & 0x300) == 0x300) || (((param_2 & 0xf0) != 0 && (param_5 != 0)))) ||
      (((param_2 & 0x100) != 0 && ((param_5 == 0 || ((int)param_1 < 0)))))) ||
     (((param_3 != 0 && (param_4 == 0)) ||
      (((((param_2 & 0x400) != 0 && (param_5 != 0)) && (0x1ffff < param_5 + 0xbff80000U)) &&
       (0x1fff < param_5 + 0xbff40000U)))))) {
    return 0x102;
  }
  if ((param_2 & 0xfe) == 0) {
    uVar5 = 2;
    if ((param_2 & 0x100) == 0) {
      uVar5 = 0xe;
    }
    param_2 = param_2 | uVar5;
  }
  if (param_1 == 0xffffffff) {
    uVar5 = 6;
LAB_4011e7e1:
    if (param_1 == 0xfffffffa) {
      uVar5 = 0xb;
    }
  }
  else {
    uVar5 = 0xf;
    if (param_1 == 0xfffffffe) goto LAB_4011e7e1;
    uVar5 = 0x10;
    if (((param_1 != 0xfffffffd) && (uVar5 = 7, param_1 != 0xfffffffc)) &&
       (uVar5 = 0x1d, param_1 != 0xfffffffb)) {
      uVar5 = 0xffffffff;
      goto LAB_4011e7e1;
    }
  }
  memw();
  puVar1 = (undefined4 *)(*(code *)&SUB_40083fe0)(8,0x804);
  if (puVar1 != (undefined4 *)0x0) {
    memw();
    (*(code *)&SUB_40092a98)(0x3ffbe108,0xffffffff);
    uVar6 = rsr(in_PRID);
    uVar6 = uVar6 >> 0xd & 1;
    memw();
    (*(code *)&SUB_4008b530)(local_2c,0,0xc);
    uStack_48 = param_2;
    if ((param_2 & 0xfe) == 0) {
      uStack_48 = param_2 | 0xe;
    }
    pcVar12 = &DAT_00000004;
    for (puVar2 = _DAT_3ffc66e0; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[2]) {
      uVar8 = *puVar2;
      if (((uint)(ushort)*puVar2 & (uint)pcVar12) == 0) {
        if ((param_1 == (int)(uVar8 << 2) >> 0x18) && (uVar6 == (uVar8 >> 0x10 & 1))) {
LAB_4011e8f8:
          if ((uVar5 != 0xffffffff) && (uVar5 != (uVar8 >> 0x11 & 0x1f))) goto LAB_4011e8c0;
          memw();
          iVar3 = FUN_4011e5e0(puVar2,uStack_48,uVar6,uVar5);
          if (iVar3 == 0) goto LAB_4011e8c0;
          uVar5 = *puVar2;
          goto LAB_4011e91a;
        }
      }
      else if (uVar6 == (uVar8 >> 0x10 & 1)) {
        piVar9 = (int *)puVar2[1];
        if (piVar9 == (int *)0x0) {
          pcVar12 = "_usable";
          puVar2 = in_t0;
          piVar9 = (int *)(*(code *)&SUB_40094c54)("support/intr_alloc.c",0xa7,"_usable","alloc.c");
          in_t0 = puVar2;
        }
        do {
          if (param_1 == (*piVar9 << 0x17) >> 0x18) goto LAB_4011e8f8;
          piVar9 = (int *)piVar9[5];
        } while (piVar9 != (int *)0x0);
      }
    }
    if (uVar5 == 0xffffffff) {
      iStack_4c = 9;
      iStack_44 = 0x7fffffff;
      uVar5 = 0;
      uVar8 = 0xffffffff;
      do {
        memw();
        puVar2 = (uint *)FUN_4011e5bc(uVar5,uVar6);
        if (puVar2 == (uint *)0x0) {
          local_2c[0] = local_2c[0] & 0xffc1ffff | (uVar5 & 0x1f) << 0x11;
          puVar2 = local_2c;
        }
        memw();
        iVar3 = FUN_4011e5e0(puVar2,uStack_48,uVar6,0xffffffff);
        if (iVar3 == 0) goto LAB_4011e8b8;
        if ((uStack_48 & 0x100) == 0) {
          iVar3 = FUN_401237ec(uVar5);
joined_r0x4011e9df:
          if (iVar3 < iStack_4c) {
LAB_4011e9cd:
            memw();
            uVar8 = uVar5;
            iStack_4c = iVar3;
          }
        }
        else if ((*puVar2 & 4) == 0) {
          if (uVar8 == 0xffffffff) {
            iVar3 = FUN_401237ec(uVar5);
            goto joined_r0x4011e9df;
          }
        }
        else {
          iVar7 = 0;
          for (uVar11 = puVar2[1]; uVar11 != 0; uVar11 = *(uint *)(uVar11 + 0x14)) {
            iVar7 = iVar7 + 1;
          }
          iVar3 = FUN_401237ec(uVar5);
          if ((iVar7 < iStack_44) || (iVar3 < iStack_4c)) {
            memw();
            iStack_44 = iVar7;
            goto LAB_4011e9cd;
          }
        }
LAB_4011e8b8:
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0x20);
      if (uVar8 == 0xffffffff) goto LAB_4011e8c0;
    }
    else {
      puVar2 = (uint *)FUN_4011e5bc(uVar5,uVar6);
      if (puVar2 == (uint *)0x0) {
        local_2c[0] = local_2c[0] & 0xffc1ffff | (uVar5 & 0x1f) << 0x11;
        puVar2 = local_2c;
      }
      memw();
      iVar3 = FUN_4011e5e0(puVar2,uStack_48,uVar6,uVar5);
      if (iVar3 == 0) {
LAB_4011e8c0:
        (*(code *)&SUB_40092bec)(0x3ffbe108);
        (*(code *)&SUB_40094d80)(puVar1);
        return 0x105;
      }
      uVar5 = *puVar2;
LAB_4011e91a:
      uVar8 = uVar5 >> 0x11 & 0x1f;
    }
    puVar2 = (uint *)FUN_4011e684(uVar8,uVar6);
    if (puVar2 != (uint *)0x0) {
      if ((param_2 & 0x100) == 0) {
        *(ushort *)puVar2 = 8;
        memw();
        if (param_5 != 0) {
          memw();
          FUN_4011f6cc(uVar8 & 0xff,param_5,param_6);
        }
        if ((param_2 & 0x200) != 0) {
          (*(code *)&SUB_4009651c)(1 << 0x20 - (0x20 - (uVar8 & 0x1f)));
        }
        *puVar2 = *puVar2 & 0xc03fffff | (param_1 & 0xff) << 0x16;
        memw();
LAB_4011ea5a:
        puVar10 = (uint *)(uVar6 * 4 + 0x3ffc66d8);
        uVar5 = 1 << 0x20 - (0x20 - (uVar8 & 0x1f));
        uVar11 = *puVar10;
        if ((param_2 & 0x400) == 0) {
          *(ushort *)puVar2 = (ushort)*puVar2 & 0xfffd;
          memw();
          uVar5 = uVar5 | uVar11;
          memw();
        }
        else {
          *(ushort *)puVar2 = (ushort)*puVar2 | 2;
          memw();
          uVar5 = (uVar5 ^ 0xffffffff) & uVar11;
        }
        *puVar10 = uVar5;
        if (-1 < (int)param_1) {
          memw();
          (*(code *)&SUB_4000681c)(uVar6,param_1,uVar8);
        }
        *puVar1 = puVar2;
        puVar1[1] = puVar2[1];
        memw();
        FUN_4011e724(uVar8);
        if ((param_2 & 0x800) != 0) {
          (*(code *)&SUB_400844a4)(puVar1);
        }
        (*(code *)&SUB_40092bec)(0x3ffbe108);
        if (param_7 == (undefined4 *)0x0) {
          (*(code *)&SUB_40094d80)(puVar1);
        }
        else {
          *param_7 = puVar1;
        }
        memw();
        return 0;
      }
      iVar3 = (*(code *)&SUB_40094d60)(0x18);
      if (iVar3 != 0) {
        puVar4 = (ushort *)(*(code *)&SUB_4008b530)(iVar3,0,0x18);
        *(int *)(puVar4 + 2) = param_3;
        *(int *)(puVar4 + 6) = param_5;
        uVar5 = puVar2[1];
        *(int *)(puVar4 + 4) = param_4;
        *(uint *)(puVar4 + 10) = uVar5;
        *(undefined4 *)(puVar4 + 8) = param_6;
        *puVar4 = *puVar4 & 0xfe00 | (ushort)((param_1 & 0xff) << 1);
        memw();
        puVar2[1] = (uint)puVar4;
        *(ushort *)puVar2 = (ushort)*puVar2 | 4;
        memw();
        memw();
        FUN_4011f6cc(uVar8 & 0xff,0x4008433c,puVar2);
        goto LAB_4011ea5a;
      }
    }
    (*(code *)&SUB_40092bec)(0x3ffbe108);
    (*(code *)&SUB_40094d80)(puVar1);
  }
  return 0x101;
}

