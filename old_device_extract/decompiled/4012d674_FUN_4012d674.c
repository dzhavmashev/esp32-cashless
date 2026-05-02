// Function : FUN_4012d674
// Address  : 0x4012d674
// Size     : 108 bytes


void FUN_4012d674(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_2c [44];
  
  uVar1 = FUN_40138f28(param_6);
  uVar2 = FUN_401864c4();
  *param_3 = uVar2;
  memw();
  FUN_40138f64(auStack_2c);
  iVar3 = FUN_4013905c(auStack_2c,uVar1,0);
  if ((((iVar3 == 0) && (iVar3 = FUN_40139114(auStack_2c), iVar3 == 0)) &&
      (iVar3 = FUN_40139174(auStack_2c,*(int *)(param_1 + 0x44) + 0x470,0x40), iVar3 == 0)) &&
     (iVar3 = FUN_40139174(auStack_2c,param_4,param_5), iVar3 == 0)) {
    iVar3 = FUN_401391c4(auStack_2c,param_2);
  }
  FUN_40138f78(auStack_2c);
  if (iVar3 != 0) {
    FUN_4012a73c(param_1,2,0x50);
  }
  return;
}

