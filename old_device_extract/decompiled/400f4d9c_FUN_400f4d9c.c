// Function : FUN_400f4d9c
// Address  : 0x400f4d9c
// Size     : 456 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f4d9c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  
  if (_DAT_3ffc5554 == 0) {
    iVar1 = FUN_400f4cfc();
    if (iVar1 != 0) {
      return iVar1;
    }
    if (_DAT_3ffc5554 == 0) {
      uVar2 = (*(code *)&SUB_40094b80)();
      memw();
      FUN_4012113c(1,"llup_en","hz",uVar2,"llup_en","t_value",0x15e,"en");
      return 0x103;
    }
  }
  uVar5 = param_1[7];
  uVar6 = param_1[8];
  if ((uVar5 & 0xff) < 8) {
    if ((uVar6 & 0xff) < 2) {
      iVar1 = *param_1;
      iVar7 = param_1[1];
      if ((iVar1 < 0) ||
         ((uVar4 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,iVar1), ((uVar4 ^ 0xffffffff) & 1) == 0
          && (iVar1 != iVar7)))) {
        if ((iVar7 < 0) ||
           (uVar4 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,iVar7), (uVar4 & 1) != 0)) {
          if (((uint)param_1[4] < 3) && ((uint)param_1[5] < 3)) {
            if (((uint)param_1[3] < 3) && ((uint)param_1[2] < 3)) {
              if (DAT_3ffc5550 == '\0') {
                FUN_400f56b0(0x52);
                DAT_3ffc5550 = '\x01';
                memw();
              }
              memw();
              FUN_400f552c(0x52);
              uVar5 = uVar5 & 0xff;
              FUN_400f4678(uVar5,0x20,(int)(short)param_1[6]);
              uVar6 = uVar6 & 0xff;
              FUN_400f4678(uVar5,0x10,(int)*(short *)((int)param_1 + 0x1a));
              FUN_400f4840(uVar5,0x20,0);
              FUN_400f4840(uVar5,0x10,0);
              FUN_400f4840(uVar5,0x40,0);
              FUN_400f45e4(uVar5,0);
              FUN_400f4b58(uVar5,uVar6,param_1[4],param_1[5],param_1[3],param_1[2]);
              FUN_400f49a8(uVar5,uVar6,iVar1,iVar7);
              return 0;
            }
            uVar2 = (*(code *)&SUB_40094b80)();
            pcVar8 = "E ERROR";
            uVar3 = 0x169;
            memw();
          }
          else {
            uVar2 = (*(code *)&SUB_40094b80)();
            pcVar8 = "M ERROR";
            uVar3 = 0x168;
            memw();
          }
        }
        else {
          uVar2 = (*(code *)&SUB_40094b80)();
          pcVar8 = "o error";
          uVar3 = 0x167;
          memw();
        }
      }
      else {
        uVar2 = (*(code *)&SUB_40094b80)();
        pcVar8 = " error\n";
        uVar3 = 0x166;
        memw();
      }
    }
    else {
      uVar2 = (*(code *)&SUB_40094b80)();
      pcVar8 = "e error";
      uVar3 = 0x165;
      memw();
    }
  }
  else {
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar8 = "r error";
    uVar3 = 0x164;
  }
  memw();
  FUN_4012113c(1,"llup_en","hz",uVar2,"llup_en","t_value",uVar3,pcVar8);
  return 0x102;
}

