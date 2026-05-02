// Function : FUN_4018d55c
// Address  : 0x4018d55c
// Size     : 323 bytes


int FUN_4018d55c(int param_1,char *param_2,int param_3,char *param_4,undefined4 param_5,
                undefined4 param_6,undefined1 param_7)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 != 0) goto LAB_4018d580;
  uVar4 = 0x2b9;
  param_4 = "failed\n";
  while( true ) {
    memw();
    (*(code *)&SUB_40094c54)("p_event/esp_event.c",uVar4,"nternal");
LAB_4018d580:
    if (param_4 != (char *)0x0) break;
    param_4 = "oop %p\n";
    uVar4 = 0x2ba;
  }
  if ((param_2 == (char *)0x0) && (param_3 != -1)) {
    uVar4 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"unknown event","handler",uVar4,"unknown event");
    iVar2 = 0x102;
  }
  else {
    if (param_2 == (char *)0x0) {
      param_2 = "failed\n";
    }
    memw();
    (*(code *)&SUB_4009019c)(*(undefined4 *)(param_1 + 0x10),0xffffffff);
    iVar3 = 0;
    for (iVar2 = *(int *)(param_1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      iVar3 = iVar2;
    }
    if ((iVar3 == 0) || ((*(int *)(iVar3 + 4) != 0 && (param_2 == "failed\n" && param_3 == -1)))) {
      memw();
      puVar1 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0xc);
      if (puVar1 == (undefined4 *)0x0) {
        uVar4 = (*(code *)&SUB_40094b80)();
        FUN_4012113c(1,"unknown event","ported\n",uVar4,"unknown event");
        iVar2 = 0x101;
      }
      else {
        *puVar1 = 0;
        puVar1[1] = 0;
        memw();
        iVar2 = FUN_4018d0d0(puVar1,param_2,param_3,param_4,param_5,param_6,param_7);
        if (iVar2 == 0) {
          if (iVar3 == 0) {
            uVar4 = *(undefined4 *)(param_1 + 0x14);
            *(undefined4 **)(param_1 + 0x14) = puVar1;
            puVar1[2] = uVar4;
            memw();
          }
          else {
            puVar1[2] = *(undefined4 *)(iVar3 + 8);
            *(undefined4 **)(iVar3 + 8) = puVar1;
            memw();
          }
        }
        else {
          (*(code *)&SUB_40094d80)(puVar1);
        }
      }
    }
    else {
      memw();
      iVar2 = FUN_4018d0d0(iVar3,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    (*(code *)&SUB_4008fc8c)(*(undefined4 *)(param_1 + 0x10));
  }
  return iVar2;
}

