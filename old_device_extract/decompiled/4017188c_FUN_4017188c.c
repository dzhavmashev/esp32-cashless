// Function : FUN_4017188c
// Address  : 0x4017188c
// Size     : 906 bytes


int FUN_4017188c(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  code *pcVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  uint *local_50;
  uint *puStack_4c;
  uint auStack_48 [2];
  uint *puStack_40;
  uint *puStack_3c;
  uint uStack_38;
  uint *puStack_34;
  uint *puStack_30;
  code *pcStack_2c;
  
  uVar8 = param_1[4];
  if ((uVar8 & 1) != 0) goto LAB_40171896;
  puVar2 = (uint *)(uVar8 >> 0xb);
  if (puVar2 == (uint *)0x0) {
    piVar5 = (int *)param_1[3];
    if ((uVar8 & 2) != 0) {
      for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
        iVar4 = FUN_401715b8(param_1);
        if (iVar4 == -1) goto LAB_401718ba;
        puVar2 = (uint *)((int)puVar2 + iVar4);
      }
LAB_401718e1:
      if ((uint *)((uint)puVar2 & 0x1fffff) == puVar2) {
        uVar8 = param_1[4] & 0x7ff | (int)puVar2 << 0xb;
      }
      else {
        uVar8 = param_1[4] & 0x7ff;
      }
      param_1[4] = uVar8;
      goto LAB_401718fd;
    }
    puVar2 = (uint *)FUN_401715b8(param_1,piVar5);
    if (puVar2 != (uint *)0xffffffff) goto LAB_401718e1;
LAB_401718ba:
    param_1[4] = 0x7f8;
    param_1[3] = (uint)&DAT_3f424d98;
  }
  else {
LAB_401718fd:
    if ((DAT_3ffc076c != '\0') && (puVar2 != (uint *)0x0)) {
      iVar4 = ((int)puVar2 + 2U) * 4;
      local_50 = (uint *)(*(code *)&SUB_40094d60)(iVar4);
      if (local_50 != (uint *)0x0) {
        local_50[1] = 0;
        puStack_4c = (uint *)(*(code *)&SUB_40094d60)(iVar4);
        if (puStack_4c != (uint *)0x0) {
          puStack_4c[1] = 0;
        }
        piVar5 = (int *)param_1[3];
        if ((param_1[4] & 2) == 0) {
          FUN_401717d8(param_1,&local_50,piVar5);
        }
        else {
          for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
            FUN_401717d8(param_1,&local_50);
          }
        }
        uVar8 = 0;
        puVar6 = local_50;
        if (local_50 == (uint *)0x0) goto LAB_40171972;
        if (puVar2 == (uint *)local_50[1]) goto LAB_40171972;
        do {
          (*(code *)&SUB_40094bc8)();
LAB_40171972:
          pcVar12 = (code *)0x40171734;
          if (((param_1[4] & 4) == 0) && (pcVar12 = (code *)0x40171784, (param_1[4] & 0x7f8) != 0))
          {
            pcVar12 = FUN_401714dc;
          }
          if (puStack_4c == (uint *)0x0) {
            FUN_4017133c(param_1,pcVar12,puVar6);
            goto LAB_40171aa9;
          }
          uVar11 = puVar6[1];
          puStack_40 = puVar6 + uVar11;
          puVar15 = puStack_4c + 2;
          puVar9 = (uint *)&DAT_3ffc7ebc;
          puVar14 = puStack_4c;
          for (puVar3 = puVar6; puStack_40 != puVar3; puVar3 = puVar3 + 1) {
            while ((puVar9 != (uint *)&DAT_3ffc7ebc &&
                   (puStack_3c = puVar3, uStack_38 = uVar11, puStack_34 = puVar15,
                   puStack_30 = puVar14, pcStack_2c = pcVar12,
                   iVar4 = (*pcVar12)(param_1,puVar3[2],*puVar9), pcVar12 = pcStack_2c,
                   puVar14 = puStack_30, puVar3 = puStack_3c, puVar15 = puStack_34,
                   uVar11 = uStack_38, iVar4 < 0))) {
              puVar10 = *(uint **)((int)puStack_30 + (int)((int)puVar9 + (8 - (int)(puVar6 + 2))));
              *(undefined4 *)((int)puStack_30 + (int)((int)puVar9 + (8 - (int)(puVar6 + 2)))) = 0;
              puVar9 = puVar10;
            }
            *puVar15 = (uint)puVar9;
            puVar9 = puVar3 + 2;
            puVar15 = puVar15 + 1;
          }
          iVar4 = 8;
          uVar7 = uVar8;
          for (uVar13 = uVar8; uVar11 != uVar13; uVar13 = uVar13 + 1) {
            if (*(int *)((int)puVar14 + iVar4) == 0) {
              puVar14[uVar7 + 2] = *(uint *)((int)puVar6 + iVar4);
              uVar7 = uVar7 + 1;
            }
            else {
              puVar6[uVar8 + 2] = *(uint *)((int)puVar6 + iVar4);
              uVar8 = uVar8 + 1;
            }
            iVar4 = iVar4 + 4;
          }
          puVar6[1] = uVar8;
          puVar14[1] = uVar7;
          uVar8 = puStack_4c[1];
          puVar6 = (uint *)(local_50[1] + uVar8);
        } while (puVar2 != puVar6);
        pcStack_2c = pcVar12;
        FUN_4017133c(param_1,pcVar12);
        puVar2 = local_50;
        uVar8 = puStack_4c[1];
        if (uVar8 != 0) {
          puVar6 = (uint *)(uVar8 << 2);
          uVar11 = local_50[1];
          pcVar12 = pcStack_2c;
          puVar9 = puStack_4c;
          do {
            uVar8 = uVar8 - 1;
            puVar3 = puVar2 + uVar11 + 1;
            puVar14 = *(uint **)((int)puVar9 + (int)puVar6 + 4);
            while (uVar11 != 0) {
              uStack_38 = uVar11 - 1;
              puStack_3c = puVar9;
              puStack_34 = puVar14;
              puStack_30 = puVar6;
              pcStack_2c = pcVar12;
              iVar4 = (*pcVar12)(param_1,*puVar3,puVar14);
              pcVar12 = pcStack_2c;
              puVar6 = puStack_30;
              puVar9 = puStack_3c;
              puVar14 = puStack_34;
              if (iVar4 < 1) break;
              *(uint *)((int)puVar3 + (int)puStack_30) = *puVar3;
              puVar3 = puVar3 + -1;
              uVar11 = uStack_38;
            }
            puVar2[uVar11 + uVar8 + 2] = (uint)puVar14;
            puVar6 = puVar6 + -1;
          } while (uVar8 != 0);
          puVar2[1] = puVar2[1] + puVar9[1];
        }
        (*(code *)&SUB_40094d80)(puStack_4c);
LAB_40171aa9:
        *local_50 = param_1[3];
        param_1[3] = (uint)local_50;
        param_1[4] = param_1[4] | 1;
      }
    }
  }
  if (param_2 < *param_1) {
    return 0;
  }
LAB_40171896:
  uVar8 = param_1[4];
  piVar5 = (int *)param_1[3];
  if ((uVar8 & 1) == 0) {
    if ((uVar8 & 2) == 0) {
      iVar4 = FUN_40171674(param_1,piVar5,param_2);
      return iVar4;
    }
    for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
      iVar4 = FUN_40171674(param_1,*piVar5,param_2);
      if (iVar4 != 0) {
        return iVar4;
      }
    }
  }
  else if ((uVar8 & 4) == 0) {
    if ((uVar8 & 0x7f8) == 0) {
      uVar8 = 0;
      uVar11 = piVar5[1];
      while (uVar7 = uVar11, uVar8 < uVar7) {
        uVar11 = uVar8 + uVar7 >> 1;
        iVar4 = piVar5[uVar11 + 2];
        if (*(uint *)(iVar4 + 8) <= param_2) {
          if (param_2 < *(uint *)(iVar4 + 8) + *(int *)(iVar4 + 0xc)) {
            return iVar4;
          }
          uVar8 = uVar11 + 1;
          uVar11 = uVar7;
        }
      }
    }
    else {
      uVar7 = uVar8 >> 3 & 0xff;
      puStack_34 = (uint *)FUN_401713c4(uVar7,param_1);
      pcStack_2c = (code *)piVar5[1];
      uVar11 = 0;
      while (uVar11 < pcStack_2c) {
        uVar13 = uVar11 + (int)pcStack_2c >> 1;
        iVar4 = piVar5[uVar13 + 2];
        puStack_30 = (uint *)pcStack_2c;
        pcStack_2c = (code *)uVar13;
        uVar1 = FUN_40171410(uVar7,puStack_34,iVar4 + 8,auStack_48);
        FUN_40171410(uVar8 >> 3 & 0xf,0,uVar1,&local_50);
        if (auStack_48[0] <= param_2) {
          if (param_2 < auStack_48[0] + (int)local_50) {
            return iVar4;
          }
          uVar11 = (int)pcStack_2c + 1;
          pcStack_2c = (code *)puStack_30;
        }
      }
    }
  }
  else {
    puStack_30 = (uint *)0x0;
    pcVar12 = (code *)piVar5[1];
    while (puStack_30 < pcVar12) {
      uVar11 = (uint)((int)puStack_30 + (int)pcVar12) >> 1;
      iVar4 = piVar5[uVar11 + 2];
      pcStack_2c = pcVar12;
      uVar8 = FUN_40171728(iVar4);
      puStack_34 = (uint *)(uVar8 & 0xff);
      uVar1 = FUN_401713c4(puStack_34,param_1);
      uVar1 = FUN_40171410(puStack_34,uVar1,iVar4 + 8,auStack_48);
      FUN_40171410(uVar8 & 0xf,0,uVar1,&local_50);
      pcVar12 = (code *)uVar11;
      if (auStack_48[0] <= param_2) {
        if (param_2 < auStack_48[0] + (int)local_50) {
          return iVar4;
        }
        puStack_30 = (uint *)(uVar11 + 1);
        pcVar12 = pcStack_2c;
      }
    }
  }
  return 0;
}

