// Function : FUN_400f6e54
// Address  : 0x400f6e54
// Size     : 715 bytes


undefined4 FUN_400f6e54(int param_1,uint *param_2,uint *param_3,uint *param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  char *pcVar7;
  uint *in_t0;
  
  if (param_1 < 0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    uVar2 = 0x2af;
  }
  else {
    if (param_1 < 3) {
      if (((int)param_2 < 0) ||
         (uVar3 = (*(code *)&SUB_4000c84c)(0xeffffff,3,param_2), (uVar3 & 1) != 0)) {
        if (((int)param_3 < 0) ||
           (uVar3 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_3), (uVar3 & 1) != 0)) {
          if (((int)param_4 < 0) ||
             (uVar3 = (*(code *)&SUB_4000c84c)(0xeffffff,3,param_4), (uVar3 & 1) != 0)) {
            if ((param_5 < 0) ||
               (uVar3 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_5), (uVar3 & 1) != 0)) {
              if ((int)param_2 < 0) goto LAB_400f6fd9;
              iVar4 = FUN_400f5c78(param_1,param_2,0);
              if (iVar4 != 0) goto LAB_400f6fd9;
              puVar6 = *(uint **)(&DAT_3f413ee8 + (int)param_2 * 4);
              puVar5 = (uint *)0x0;
              if ((uint *)0x13ffc < puVar6 + -0xffc0000) goto LAB_400f6f9a;
LAB_400f6f88:
              puVar6 = in_t0;
              (*(code *)&SUB_40094c54)("ude/hal/gpio_ll.h",0x27d,"_config","t->num)");
              in_t0 = puVar6;
LAB_400f6f9a:
              memw();
              memw();
              *puVar6 = *puVar6 & 0xffff8fff | 0x2000;
              memw();
              FUN_400f3e98(param_2,1);
              (*(code *)&SUB_40009f0c)
                        (param_2,*(uint *)(&DAT_3f41450c + param_1 * 0x18) >> 0x14,puVar5,puVar5);
LAB_400f6fd9:
              if ((-1 < (int)param_3) && (iVar4 = FUN_400f5c78(param_1,param_3,1), iVar4 == 0))
              goto code_r0x400f6fec;
              goto LAB_400f7045;
            }
            uVar1 = (*(code *)&SUB_40094b80)();
            uVar2 = 0x2b4;
            pcVar7 = " error\n";
            memw();
          }
          else {
            uVar1 = (*(code *)&SUB_40094b80)();
            uVar2 = 0x2b3;
            pcVar7 = " error\n";
            memw();
          }
        }
        else {
          uVar1 = (*(code *)&SUB_40094b80)();
          uVar2 = 0x2b2;
          pcVar7 = " error\n";
          memw();
        }
      }
      else {
        uVar1 = (*(code *)&SUB_40094b80)();
        uVar2 = 0x2b1;
        pcVar7 = " error\n";
        memw();
      }
      goto LAB_400f6e75;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    uVar2 = 0x2b0;
  }
  pcVar7 = "_select";
LAB_400f6e75:
  memw();
  FUN_4012113c(1,"th",pcVar7,uVar1,"th","unc_sel",uVar2);
  return 0xffffffff;
code_r0x400f6fec:
  puVar6 = *(uint **)(&DAT_3f413ee8 + (int)param_3 * 4);
  param_2 = puVar6 + -0xffc0000;
  puVar5 = (uint *)0x0;
  if ((uint *)0x13ffc < param_2) {
    memw();
    memw();
    *puVar6 = *puVar6 & 0xffff8fff | 0x2000;
    memw();
    FUN_400f3fc0(param_3,0);
    FUN_400f4054(param_3,1);
    (*(code *)&SUB_40009edc)(param_3,*(uint *)(&DAT_3f414510 + param_1 * 0x18) >> 0x14,0);
LAB_400f7045:
    if ((-1 < (int)param_4) && (iVar4 = FUN_400f5c78(param_1,param_4,2), iVar4 == 0)) {
      puVar5 = *(uint **)(&DAT_3f413ee8 + (int)param_4 * 4);
      param_2 = puVar5 + -0xffc0000;
      if (param_2 < (uint *)0x13ffd) {
        param_3 = (uint *)0x0;
        goto LAB_400f6f88;
      }
      memw();
      memw();
      *puVar5 = *puVar5 & 0xffff8fff | 0x2000;
      memw();
      FUN_400f4054(param_4,2);
      (*(code *)&SUB_40009f0c)(param_4,*(uint *)(&DAT_3f414514 + param_1 * 0x18) >> 0x14,0,0);
    }
    if ((param_5 < 0) || (iVar4 = FUN_400f5c78(param_1,param_5,3), iVar4 != 0)) {
      return 0;
    }
    param_4 = *(uint **)(&DAT_3f413ee8 + param_5 * 4);
    param_3 = param_4 + -0xffc0000;
    puVar5 = (uint *)0x13ffc;
    if ((uint *)0x13ffc < param_3) {
      memw();
      memw();
      *param_4 = *param_4 & 0xffff8fff | 0x2000;
      memw();
      FUN_400f3fc0(param_5,0);
      FUN_400f4054(param_5,1);
      (*(code *)&SUB_40009edc)(param_5,*(uint *)(&DAT_3f414518 + param_1 * 0x18) >> 0x14,0);
      return 0;
    }
    param_2 = (uint *)0x0;
  }
  goto LAB_400f6f88;
}

