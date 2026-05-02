// Function : FUN_4013bb58
// Address  : 0x4013bb58
// Size     : 323 bytes


int FUN_4013bb58(int param_1,code *param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,uint param_7,undefined4 param_8,undefined1 *param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 auStack_2c [44];
  
  if ((((param_4 != 1) || (*(int *)(param_1 + 0xa4) == 1)) && (param_2 != (code *)0x0)) &&
     (iVar1 = FUN_40138f28(*(undefined4 *)(param_1 + 0xa8)), iVar1 != 0)) {
    uVar2 = *(uint *)(param_1 + 4);
    uVar3 = FUN_401864c4();
    uVar5 = param_7 + 2 + (uVar3 & 0xffff) * 2;
    if ((uVar5 <= uVar2) && (param_7 <= uVar5)) {
      memw();
      (*(code *)&SUB_4008b530)(param_9,0,uVar2);
      *param_9 = 0;
      memw();
      puVar6 = param_9 + 1;
      memw();
      iVar4 = (*param_2)(param_3,puVar6,uVar3);
      iVar7 = iVar4 + -0x4480;
      if (iVar4 == 0) {
        puVar8 = puVar6 + uVar3;
        memw();
        iVar7 = FUN_40139210(iVar1,param_5,param_6,puVar8);
        if (iVar7 == 0) {
          puVar8[(uVar2 - param_7) + -2 + uVar3 + (uVar3 & 0xffff) * -2] = 1;
          memw();
          if (param_7 != 0) {
            memw();
            (*(code *)&SUB_4008b3d0)
                      (puVar8 + (uVar2 - param_7) + -2 + uVar3 + (uVar3 & 0xffff) * -2 + 1,param_8,
                       param_7);
          }
          FUN_40138f64(auStack_2c);
          iVar7 = FUN_4013905c(auStack_2c,iVar1,0);
          if (iVar7 == 0) {
            iVar1 = (uVar2 - 1) - uVar3;
            iVar7 = FUN_4013ae6c(param_9 + uVar3 + 1,iVar1,puVar6,uVar3,auStack_2c);
            if (iVar7 == 0) {
              iVar7 = FUN_4013ae6c(puVar6,uVar3,param_9 + uVar3 + 1,iVar1,auStack_2c);
            }
          }
          memw();
          FUN_40138f78(auStack_2c);
          if (iVar7 == 0) {
            if (param_4 == 0) {
              iVar7 = FUN_4013b510(param_1,param_9,param_9);
            }
            else {
              iVar7 = FUN_4013b574(param_1,param_2,param_3,param_9,param_9);
            }
          }
        }
      }
      goto LAB_4013bb78;
    }
  }
  iVar7 = -0x4080;
LAB_4013bb78:
  memw();
  return iVar7;
}

