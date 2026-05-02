// Function : FUN_40101278
// Address  : 0x40101278
// Size     : 598 bytes


int FUN_40101278(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  uint uVar10;
  char *pcVar11;
  
  if (((param_1 == (int *)0x0) || (*(int *)(*param_1 + 0x18) == 0)) ||
     (iVar2 = FUN_40100700(), iVar2 != 0)) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"t fail\n",uVar1,&PTR_s_STA_DEF_3f40e714,"art_api",
                 param_1);
  }
  else {
    memw();
    iVar2 = (*(code *)&SUB_40094dd8)(1,0x5c);
    if (iVar2 == 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar3 = FUN_4018de58();
      memw();
      FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"e key)\n",uVar1,&PTR_s_STA_DEF_3f40e714,0x5c,uVar3);
      return 0;
    }
    puVar4 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0xc);
    if (puVar4 == (undefined4 *)0x0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar3 = FUN_4018de58();
      memw();
      FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"e key)\n",uVar1,&PTR_s_STA_DEF_3f40e714,0xc,uVar3);
    }
    else {
      *(undefined4 **)(iVar2 + 8) = puVar4;
      memw();
      puVar5 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0xc);
      if (puVar5 == (undefined4 *)0x0) {
        uVar1 = (*(code *)&SUB_40094b80)();
        uVar3 = FUN_4018de58();
        memw();
        FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"e key)\n",uVar1,&PTR_s_STA_DEF_3f40e714,0xc,uVar3);
      }
      else {
        *(undefined4 **)(iVar2 + 0xc) = puVar5;
        memw();
        iVar6 = (*(code *)&SUB_40094dd8)(1,0x124);
        if (iVar6 != 0) {
          puVar8 = (uint *)*param_1;
          *(int *)(iVar6 + 0xc4) = iVar2;
          *(int *)(iVar2 + 0x10) = iVar6;
          if ((puVar8 == (uint *)0x0) || (piVar9 = (int *)param_1[2], piVar9 == (int *)0x0)) {
            uVar1 = 0x5001;
          }
          else {
            memw();
            (*(code *)&SUB_4008b3d0)(iVar2,puVar8 + 1,6);
            if (puVar8[3] == 0) {
              *puVar4 = 0;
              puVar4[2] = 0;
              puVar4[1] = 0;
            }
            else {
              (*(code *)&SUB_4008b3d0)(puVar4,puVar8[3],0xc);
            }
            uVar3 = puVar4[1];
            uVar1 = puVar4[2];
            *puVar5 = *puVar4;
            puVar5[1] = uVar3;
            puVar5[2] = uVar1;
            *(uint *)(iVar2 + 0x44) = puVar8[5];
            *(uint *)(iVar2 + 0x40) = puVar8[4];
            uVar7 = *puVar8;
            uVar10 = puVar8[6];
            *(uint *)(iVar2 + 0x48) = uVar7;
            if (uVar10 != 0) {
              memw();
              uVar1 = (*(code *)&SUB_4008bfa0)();
              *(undefined4 *)(iVar2 + 0x50) = uVar1;
            }
            if (puVar8[7] != 0) {
              memw();
              uVar1 = (*(code *)&SUB_4008bfa0)();
              *(undefined4 *)(iVar2 + 0x54) = uVar1;
            }
            if (puVar8[8] != 0) {
              *(uint *)(iVar2 + 0x58) = puVar8[8];
            }
            if ((uVar7 & 0x20) == 0) {
              if ((uVar7 & 0x40) == 0) {
                if (*piVar9 != 0) {
                  *(int *)(iVar2 + 0x14) = *piVar9;
                }
                if (piVar9[1] != 0) {
                  *(int *)(iVar2 + 0x18) = piVar9[1];
                }
                piVar9 = (int *)param_1[1];
                *(int *)(iVar2 + 0x1c) = iVar6;
                if (piVar9 != (int *)0x0) {
                  if (*piVar9 != 0) {
                    *(int *)(iVar2 + 0x24) = *piVar9;
                  }
                  if (piVar9[1] != 0) {
                    *(int *)(iVar2 + 0x28) = piVar9[1];
                  }
                  if (piVar9[2] != 0) {
                    *(int *)(iVar2 + 0x2c) = piVar9[2];
                  }
                  if (piVar9[3] != 0) {
                    *(int *)(iVar2 + 0x30) = piVar9[3];
                  }
                }
                memw();
                FUN_401005c8(iVar2);
                return iVar2;
              }
              uVar1 = (*(code *)&SUB_40094b80)();
              pcVar11 = "ze %d)\n";
            }
            else {
              memw();
              uVar1 = (*(code *)&SUB_40094b80)();
              pcVar11 = "_lwip.c";
            }
            FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"p.c",uVar1,&PTR_s_STA_DEF_3f40e714,pcVar11);
            uVar1 = 0x106;
          }
          uVar3 = (*(code *)&SUB_40094b80)();
          FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,")\n",uVar3,&PTR_s_STA_DEF_3f40e714,uVar1);
          FUN_40101214(iVar2);
          return 0;
        }
        uVar1 = (*(code *)&SUB_40094b80)();
        uVar3 = FUN_4018de58();
        memw();
        FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"e key)\n",uVar1,&PTR_s_STA_DEF_3f40e714,0x124,uVar3)
        ;
        (*(code *)&SUB_40094d80)(*(undefined4 *)(iVar2 + 0xc));
      }
      (*(code *)&SUB_40094d80)(*(undefined4 *)(iVar2 + 8));
    }
    (*(code *)&SUB_40094d80)(iVar2);
  }
  return 0;
}

