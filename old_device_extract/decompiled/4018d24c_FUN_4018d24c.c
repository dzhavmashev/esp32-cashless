// Function : FUN_4018d24c
// Address  : 0x4018d24c
// Size     : 297 bytes


undefined4 FUN_4018d24c(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar5 = "failed\n";
LAB_4018d262:
    FUN_4012113c(1,"unknown event",pcVar5,uVar1,"unknown event");
    return 0x102;
  }
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar5 = "s NULL\n";
    goto LAB_4018d262;
  }
  puVar2 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0x18);
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"unknown event","s NULL\n",uVar1,"unknown event");
    return 0x101;
  }
  iVar3 = (*(code *)&SUB_4008f990)(*param_1,0x10,0);
  puVar2[1] = iVar3;
  if (iVar3 == 0) {
    memw();
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar5 = "failed\n";
  }
  else {
    iVar3 = (*(code *)&SUB_4008fcc8)(4);
    puVar2[4] = iVar3;
    if (iVar3 != 0) {
      iVar3 = param_1[1];
      puVar2[5] = 0;
      if (iVar3 == 0) {
        puVar2[2] = 0;
        *puVar2 = &DAT_3f42161d;
        memw();
LAB_4018d360:
        puVar2[3] = 0;
        *param_2 = puVar2;
        memw();
        return 0;
      }
      memw();
      iVar3 = (*(code *)&SUB_4009092c)
                        (&DAT_4018d520,iVar3,param_1[3],puVar2,param_1[2],puVar2 + 2,param_1[4]);
      if (iVar3 == 1) {
        *puVar2 = param_1[1];
        goto LAB_4018d360;
      }
      uVar4 = (*(code *)&SUB_40094b80)();
      uVar1 = 0xffffffff;
      FUN_4012113c(1,"unknown event","failed\n",uVar4,"unknown event");
      goto LAB_4018d2dc;
    }
    memw();
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar5 = "failed\n";
  }
  FUN_4012113c(1,"unknown event",pcVar5,uVar1,"unknown event");
  uVar1 = 0x101;
LAB_4018d2dc:
  if (puVar2[1] != 0) {
    (*(code *)&SUB_400902d4)();
  }
  if (puVar2[4] != 0) {
    (*(code *)&SUB_400902d4)();
  }
  (*(code *)&SUB_40094d80)(puVar2);
  return uVar1;
}

