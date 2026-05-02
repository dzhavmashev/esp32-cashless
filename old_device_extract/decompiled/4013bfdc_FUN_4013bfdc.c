// Function : FUN_4013bfdc
// Address  : 0x4013bfdc
// Size     : 172 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013bfdc(int param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 ***pppuVar2;
  undefined4 ***pppuVar3;
  undefined4 ***pppuVar4;
  undefined8 uVar5;
  undefined1 auStack_424 [1024];
  undefined4 **local_24 [9];
  
  pppuVar2 = local_24;
  memw();
  memw();
  local_24[0] = _DAT_3ffc5708;
  pppuVar4 = *(undefined4 ****)(param_1 + 4);
  pppuVar3 = pppuVar2;
  if ((param_4 == (undefined1 *)0x1) &&
     (uVar5 = CONCAT44(param_2,param_1), *(int *)(param_1 + 0xa4) != 0)) goto LAB_4013c068;
  uVar5 = CONCAT44(param_2,param_1);
  if ((undefined4 ***)0x3f0 < pppuVar4 + -4) goto LAB_4013c068;
  if (param_4 != (undefined1 *)0x0) goto LAB_4013c07e;
  memw();
  iVar1 = FUN_4013b510(param_1,param_6,auStack_424);
  while( true ) {
    if (iVar1 == 0) {
      FUN_401337dc(param_4,auStack_424,pppuVar4,param_7,param_8,param_5);
    }
    uVar5 = FUN_4013ae54(auStack_424,0x400);
    pppuVar3 = pppuVar2;
LAB_4013c068:
    pppuVar2 = _DAT_3ffc5708;
    memw();
    pppuVar4 = (undefined4 ***)*pppuVar3;
    memw();
    if (pppuVar4 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    param_4 = &DAT_3ffc5708;
LAB_4013c07e:
    iVar1 = FUN_4013b574();
  }
  return;
}

