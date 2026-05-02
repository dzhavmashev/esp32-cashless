// Function : FUN_400d7d34
// Address  : 0x400d7d34
// Size     : 267 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d7d34(int *param_1,int param_2)

{
  bool bVar1;
  undefined4 ****ppppuVar2;
  int iVar3;
  undefined4 ****ppppuVar4;
  int in_t0;
  int iVar5;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined4 ***local_34 [3];
  byte bStack_25;
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  iVar3 = *param_1;
  if (iVar3 != param_2) {
    if (iVar3 == 2) {
      FUN_400d6fd8(param_1);
      iVar5 = in_t0;
    }
    else {
      iVar5 = in_t0;
      if (iVar3 < 3) {
        if (iVar3 == 1) {
          FUN_400d6fc0(param_1);
          iVar5 = in_t0;
        }
      }
      else if (iVar3 == 3) {
        FUN_400d7020(param_1);
        iVar5 = in_t0;
      }
      else if (iVar3 == 4) {
        FUN_400d7038(param_1);
        iVar5 = in_t0;
      }
    }
    iVar3 = *param_1;
    *param_1 = param_2;
    param_1[1] = iVar3;
    FUN_400d6e54(local_44,param_1);
    ppppuVar2 = local_44;
    if ((bStack_35 & 0x80) == 0) {
      ppppuVar2 = (undefined4 ****)local_44[0];
    }
    FUN_400d6e54(local_34,param_1,*param_1);
    ppppuVar4 = local_34;
    if ((bStack_25 & 0x80) == 0) {
      ppppuVar4 = (undefined4 ****)local_34[0];
    }
    FUN_400f06a4(0x3ffc5490,"istered",ppppuVar2,ppppuVar4);
    FUN_400f0a50(local_34);
    FUN_400f0a50(local_44);
    in_t0 = *param_1;
    if (in_t0 == 3) {
      FUN_400d6fec(param_1);
      in_t0 = iVar5;
    }
    else {
      if (3 < in_t0) goto LAB_400d7e00;
      if (in_t0 == 1) {
        FUN_400d6f3c(param_1);
        in_t0 = iVar5;
      }
      else {
        bVar1 = in_t0 == 2;
        in_t0 = iVar5;
        if (bVar1) {
          FUN_400d7464(param_1);
          in_t0 = iVar5;
        }
      }
    }
  }
  while( true ) {
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    iVar5 = in_t0;
LAB_400d7e00:
    if (in_t0 == 4) {
      FUN_400d77bc(param_1);
      in_t0 = iVar5;
    }
    else {
      bVar1 = in_t0 == 5;
      in_t0 = iVar5;
      if (bVar1) {
        FUN_400d7090(param_1);
        in_t0 = iVar5;
      }
    }
  }
  return;
}

