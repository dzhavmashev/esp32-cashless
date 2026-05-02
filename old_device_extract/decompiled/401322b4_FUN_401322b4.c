// Function : FUN_401322b4
// Address  : 0x401322b4
// Size     : 243 bytes


void FUN_401322b4(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_38 = 1;
  uStack_2c = 1;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  memw();
  iVar1 = FUN_4013167c(&uStack_38,param_2);
  if ((iVar1 == 0) && (iVar1 = FUN_4013167c(&uStack_2c,param_3), iVar1 == 0)) {
    uVar2 = FUN_40186044(&uStack_38);
    uVar3 = FUN_40186044(&uStack_2c);
    if ((uVar3 == 0) && (iVar1 = FUN_4018601c(&uStack_2c,0), iVar1 == 0)) {
LAB_4013232c:
      FUN_4013167c(param_1,param_2);
    }
    else {
      uStack_2c = 1;
      uStack_38 = 1;
      do {
        memw();
        iVar1 = FUN_40131ad8(&uStack_38,0);
        if (iVar1 == 0) {
          iVar1 = FUN_40131980(&uStack_2c,(uVar2 < uVar3) * uVar2 + (uVar2 >= uVar3) * uVar3);
          if (iVar1 == 0) {
            param_2 = &uStack_2c;
            goto LAB_4013232c;
          }
          break;
        }
        uVar4 = FUN_40186044(&uStack_38);
        iVar1 = FUN_40131a34(&uStack_38,uVar4);
        if (iVar1 != 0) break;
        uVar4 = FUN_40186044(&uStack_2c);
        iVar1 = FUN_40131a34(&uStack_2c,uVar4);
        if (iVar1 != 0) break;
        iVar1 = FUN_401860ec(&uStack_38,&uStack_2c);
        if (iVar1 < 0) {
          iVar1 = FUN_40131bcc(&uStack_2c,&uStack_2c,&uStack_38);
          if (iVar1 != 0) break;
          puVar5 = &uStack_2c;
        }
        else {
          iVar1 = FUN_40131bcc(&uStack_38,&uStack_38,&uStack_2c);
          if (iVar1 != 0) break;
          puVar5 = &uStack_38;
        }
        iVar1 = FUN_40131a34(puVar5,1);
      } while (iVar1 == 0);
    }
  }
  FUN_40131548(&uStack_38);
  FUN_40131548(&uStack_2c);
  return;
}

