// Function : FUN_4013b99c
// Address  : 0x4013b99c
// Size     : 439 bytes


int FUN_4013b99c(int param_1,code *param_2,undefined4 param_3,int param_4,int param_5,
                undefined4 param_6,undefined4 param_7,uint param_8,byte *param_9)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 uStack_38;
  undefined1 auStack_2c [44];
  
  if (((param_4 != 1) || (*(int *)(param_1 + 0xa4) == 1)) && (param_2 != (code *)0x0)) {
    uVar4 = *(uint *)(param_1 + 4);
    uStack_38 = param_6;
    if (param_5 != 0) {
      iVar1 = FUN_40138f28(param_5);
      if (iVar1 == 0) goto LAB_4013b9b9;
      uStack_38 = FUN_401864c4();
    }
    memw();
    iVar1 = FUN_40138f28(*(undefined4 *)(param_1 + 0xa8));
    if (iVar1 != 0) {
      uVar2 = FUN_401864c4();
      if (param_8 == 0xffffffff) {
        uVar5 = (uVar2 & 0xffff) * 2;
        if (uVar5 <= uVar4) {
          param_8 = uVar2;
          if (uVar4 < uVar5 + 2) {
            param_8 = (uVar4 - 2) - uVar2;
          }
LAB_4013ba09:
          (*(code *)&SUB_4008b530)(param_9,0,uVar4);
          memw();
          iVar3 = FUN_40131798(param_1 + 8);
          pbVar7 = param_9 + (((uVar4 - uVar2) + -2) - param_8) + 1;
          param_9[((uVar4 - uVar2) + -2) - param_8] = 1;
          memw();
          memw();
          iVar8 = (*param_2)(param_3,pbVar7,param_8);
          if (iVar8 == 0) {
            memw();
            FUN_40138f64(auStack_2c);
            iVar8 = FUN_4013905c(auStack_2c,iVar1,0);
            if ((iVar8 == 0) && (iVar8 = FUN_40139114(auStack_2c), iVar8 == 0)) {
              pbVar6 = pbVar7 + param_8;
              iVar8 = FUN_40139174(auStack_2c,pbVar6,8);
              if (((iVar8 == 0) &&
                  (((iVar8 = FUN_40139174(auStack_2c,param_7,uStack_38), iVar8 == 0 &&
                    (iVar8 = FUN_40139174(auStack_2c,pbVar7,param_8), iVar8 == 0)) &&
                   (iVar8 = FUN_401391c4(auStack_2c,pbVar6), iVar8 == 0)))) &&
                 (uVar5 = (uint)((iVar3 - 1U & 7) == 0),
                 iVar8 = FUN_4013ae6c(param_9 + uVar5,((uVar4 - uVar2) + -1) - uVar5,pbVar6,uVar2,
                                      auStack_2c), iVar8 == 0)) {
                memw();
                iVar1 = FUN_40131798(param_1 + 8);
                *param_9 = (byte)(0xff >> ((uVar4 * 8 + 1) - iVar1 & 0x1f)) & *param_9;
                pbVar6[uVar2] = 0xbc;
                memw();
              }
            }
            memw();
            FUN_40138f78(auStack_2c);
            if (iVar8 == 0) {
              if (param_4 == 0) {
                iVar8 = FUN_4013b510(param_1,param_9,param_9);
              }
              else {
                iVar8 = FUN_4013b574(param_1,param_2,param_3,param_9,param_9);
              }
            }
          }
          else {
            iVar8 = iVar8 + -0x4480;
          }
          goto LAB_4013b9bc;
        }
      }
      else if ((-1 < (int)param_8) && (param_8 + 2 + uVar2 <= uVar4)) goto LAB_4013ba09;
    }
  }
LAB_4013b9b9:
  iVar8 = -0x4080;
LAB_4013b9bc:
  memw();
  return iVar8;
}

