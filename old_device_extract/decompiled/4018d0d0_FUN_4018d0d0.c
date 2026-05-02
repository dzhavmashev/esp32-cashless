// Function : FUN_4018d0d0
// Address  : 0x4018d0d0
// Size     : 267 bytes


int FUN_4018d0d0(int param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined1 param_7)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  bVar1 = param_3 == -1;
  if ((param_2 == "failed\n") && (bVar1)) {
    iVar2 = FUN_4018cf78(param_1,param_4,param_5,param_6,param_7);
  }
  else {
    puVar6 = (undefined4 *)0x0;
    puVar5 = (undefined4 *)0x0;
    for (puVar3 = *(undefined4 **)(param_1 + 4); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)puVar3[3]) {
      if ((char *)*puVar3 == param_2) {
        puVar6 = puVar3;
      }
      puVar5 = puVar3;
    }
    if ((((puVar5 == (undefined4 *)0x0) || (puVar6 == (undefined4 *)0x0)) ||
        ((puVar6[2] != 0 && (bVar1)))) ||
       ((((char *)*puVar5 != param_2 && (puVar5[2] != 0)) && (bVar1)))) {
      memw();
      puVar3 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0x10);
      if (puVar3 == (undefined4 *)0x0) {
        uVar4 = (*(code *)&SUB_40094b80)();
        FUN_4012113c(1,"unknown event","ed\n",uVar4,"unknown event");
        iVar2 = 0x101;
      }
      else {
        *puVar3 = param_2;
        puVar3[1] = 0;
        puVar3[2] = 0;
        memw();
        iVar2 = FUN_4018d000(puVar3,param_3,param_4,param_5,param_6,param_7);
        if (iVar2 == 0) {
          if (puVar5 == (undefined4 *)0x0) {
            uVar4 = *(undefined4 *)(param_1 + 4);
            *(undefined4 **)(param_1 + 4) = puVar3;
            puVar3[3] = uVar4;
            memw();
          }
          else {
            puVar3[3] = puVar5[3];
            puVar5[3] = puVar3;
            memw();
          }
        }
        else {
          (*(code *)&SUB_40094d80)(puVar3);
        }
      }
    }
    else {
      iVar2 = FUN_4018d000(puVar6,param_3,param_4,param_5,param_6);
    }
  }
  return iVar2;
}

