// Function : FUN_40187200
// Address  : 0x40187200
// Size     : 702 bytes


void FUN_40187200(undefined4 *param_1,uint param_2,uint param_3,code *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint auStack_80 [17];
  code *pcStack_3c;
  undefined4 *puStack_38;
  undefined4 *puStack_34;
  undefined4 *puStack_30;
  undefined4 *puStack_2c;
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  
  pcStack_3c = param_4;
  auStack_80[0x10] = 2;
  if ((((uint)param_1 | param_3) & 3) == 0) {
    auStack_80[0x10] = (uint)(param_3 != 4);
  }
  uVar8 = 0;
  do {
    while( true ) {
      puVar6 = (undefined4 *)((int)param_1 + param_3);
      puStack_30 = (undefined4 *)((int)param_1 + param_2 * param_3);
      if (6 < param_2) break;
      for (; puVar4 = puVar6, puVar6 < puStack_30; puVar6 = (undefined4 *)((int)puVar6 + param_3)) {
        while (param_1 < puVar4) {
          puVar3 = (undefined4 *)((int)puVar4 - param_3);
          iVar1 = (*pcStack_3c)(puVar3,puVar4);
          if (iVar1 < 1) break;
          if (auStack_80[0x10] == 0) {
            uVar9 = *puVar4;
            *puVar4 = *puVar3;
            *puVar3 = uVar9;
            puVar4 = puVar3;
          }
          else {
            FUN_40187168(puVar4,puVar3,param_3,auStack_80[0x10]);
            puVar4 = puVar3;
          }
        }
      }
LAB_401874bb:
      if (uVar8 == 0) {
        return;
      }
LAB_401874a0:
      uVar8 = uVar8 - 1;
      param_2 = auStack_80[uVar8 * 2 + 1];
      param_1 = (undefined4 *)auStack_80[uVar8 * 2];
    }
    puVar3 = (undefined4 *)((int)param_1 + (param_2 >> 1) * param_3);
    puVar4 = (undefined4 *)((int)param_1 + (param_2 * param_3 - param_3));
    if (param_2 != 7) {
      puVar2 = puVar4;
      puVar12 = param_1;
      if (0x28 < param_2) {
        iVar1 = (param_2 >> 3) * param_3;
        puStack_28 = puVar3;
        puStack_24 = (undefined4 *)
                     FUN_401871bc(param_1,(undefined4 *)((int)param_1 + iVar1),
                                  (undefined4 *)((int)param_1 + iVar1 + iVar1),pcStack_3c);
        puStack_28 = (undefined4 *)
                     FUN_401871bc((int)puStack_28 - iVar1,puStack_28,
                                  (undefined4 *)((int)puStack_28 + iVar1),pcStack_3c);
        iVar10 = (int)puVar4 + iVar1 * -2;
        puVar2 = (undefined4 *)FUN_401871bc(iVar10,iVar10 + iVar1,puVar4,pcStack_3c);
        puVar3 = puStack_28;
        puVar12 = puStack_24;
      }
      puVar3 = (undefined4 *)FUN_401871bc(puVar12,puVar3,puVar2,pcStack_3c);
    }
    if (auStack_80[0x10] == 0) {
      uVar9 = *param_1;
      *param_1 = *puVar3;
      *puVar3 = uVar9;
    }
    else {
      FUN_40187168(param_1,puVar3,param_3,auStack_80[0x10]);
    }
    puStack_34 = puVar4;
    puStack_38 = puVar6;
    puVar2 = (undefined4 *)0x0;
    for (puVar3 = puVar6; puVar3 <= puVar4; puVar3 = (undefined4 *)((int)puVar3 + param_3)) {
      puStack_28 = puVar2;
      iVar1 = (*pcStack_3c)(puVar3,param_1);
      puVar2 = puStack_28;
      if (iVar1 < 1) {
        if (iVar1 == 0) {
          if (auStack_80[0x10] == 0) {
            uVar9 = *puStack_38;
            *puStack_38 = *puVar3;
            *puVar3 = uVar9;
          }
          else {
            FUN_40187168(puStack_38,puVar3,param_3,auStack_80[0x10]);
          }
          puStack_38 = (undefined4 *)((int)puStack_38 + param_3);
          goto LAB_40187346;
        }
      }
      else {
        while( true ) {
          puStack_28 = puVar2;
          iVar1 = (*pcStack_3c)(puVar4,param_1);
          puStack_2c = (undefined4 *)((int)puVar4 - param_3);
          if (iVar1 < 0) break;
          puVar2 = puStack_28;
          if (iVar1 == 0) {
            if (auStack_80[0x10] == 0) {
              uVar9 = *puVar4;
              *puVar4 = *puStack_34;
              *puStack_34 = uVar9;
            }
            else {
              FUN_40187168(puVar4,puStack_34,param_3,auStack_80[0x10]);
            }
            puVar2 = (undefined4 *)0x1;
            puStack_34 = (undefined4 *)((int)puStack_34 - param_3);
          }
          puVar4 = puStack_2c;
          if (puStack_2c < puVar3) goto LAB_4018739a;
        }
        if (auStack_80[0x10] == 0) {
          uVar9 = *puVar3;
          *puVar3 = *puVar4;
          *puVar4 = uVar9;
          puVar4 = puStack_2c;
        }
        else {
          FUN_40187168(puVar3,puVar4,param_3,auStack_80[0x10]);
          puVar4 = puStack_2c;
        }
LAB_40187346:
        puVar2 = (undefined4 *)0x1;
      }
    }
LAB_4018739a:
    if (puVar2 == (undefined4 *)0x0) {
      for (; puVar4 = puVar6, puVar6 < puStack_30; puVar6 = (undefined4 *)((int)puVar6 + param_3)) {
        while (param_1 < puVar4) {
          puVar3 = (undefined4 *)((int)puVar4 - param_3);
          iVar1 = (*pcStack_3c)(puVar3,puVar4);
          if (iVar1 < 1) break;
          if (auStack_80[0x10] == 0) {
            uVar9 = *puVar4;
            *puVar4 = *puVar3;
            *puVar3 = uVar9;
            puVar4 = puVar3;
          }
          else {
            FUN_40187168(puVar4,puVar3,param_3,auStack_80[0x10]);
            puVar4 = puVar3;
          }
        }
      }
      goto LAB_401874bb;
    }
    uVar7 = (int)puVar3 - (int)puStack_38;
    iVar1 = (int)puStack_38 - (int)param_1;
    iVar1 = (uint)(iVar1 < (int)uVar7) * iVar1 + (iVar1 >= (int)uVar7) * uVar7;
    if (iVar1 != 0) {
      FUN_40187168(param_1,(int)puVar3 - iVar1,iVar1,auStack_80[0x10]);
    }
    uVar5 = (int)puStack_34 - (int)puVar4;
    uVar11 = (int)puStack_30 + (-param_3 - (int)puStack_34);
    iVar1 = (uVar11 < uVar5) * uVar11 + (uVar11 >= uVar5) * uVar5;
    if (iVar1 != 0) {
      FUN_40187168(puVar3,(int)puStack_30 - iVar1,iVar1,auStack_80[0x10]);
    }
    puVar6 = param_1;
    param_2 = uVar5;
    puVar4 = (undefined4 *)((int)puStack_30 - uVar5);
    if (uVar7 < uVar5) {
      puVar6 = (undefined4 *)((int)puStack_30 - uVar5);
      param_2 = uVar7;
      uVar7 = uVar5;
      puVar4 = param_1;
    }
    if (param_2 <= param_3) {
      if (param_3 < uVar7) goto LAB_401874b0;
      goto LAB_401874bb;
    }
    param_2 = param_2 / param_3;
    if (uVar8 < 8) {
      auStack_80[uVar8 * 2] = (uint)puVar6;
      auStack_80[uVar8 * 2 + 1] = uVar7 / param_3;
      uVar8 = uVar8 + 1;
      param_1 = puVar4;
    }
    else {
      FUN_40187200(puVar4,param_2,param_3,pcStack_3c);
      if (uVar7 <= param_3) goto LAB_401874a0;
LAB_401874b0:
      param_2 = uVar7 / param_3;
      param_1 = puVar6;
    }
  } while( true );
}

