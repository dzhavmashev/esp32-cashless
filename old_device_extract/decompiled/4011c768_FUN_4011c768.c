// Function : FUN_4011c768
// Address  : 0x4011c768
// Size     : 195 bytes


undefined4 FUN_4011c768(uint *param_1,undefined4 param_2,byte param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if (param_1 == (uint *)0x0) {
    return 0xfa;
  }
  if (param_1[1] == 3) goto LAB_4011c788;
  pcVar5 = "ng pcb!";
  uVar4 = 0x579;
  do {
    while( true ) {
      (*(code *)&SUB_40094c54)("rgument",uVar4,"o_write",pcVar5);
LAB_4011c788:
      uVar2 = param_1[0xe];
      if (uVar2 == 0) break;
      *(byte *)(uVar2 + 4) = param_3;
      memw();
      iVar3 = *(int *)(uVar2 + 0x24);
LAB_4011c7a8:
      if (((*param_1 & 0xf0) == 0x10) && (param_3 == 0)) {
        memw();
        FUN_4011c734(param_1);
      }
      bVar1 = (byte)param_1[0xd];
      param_3 = bVar1 & 4;
      *(byte *)(param_1 + 0xd) = bVar1 & 0xfb;
      memw();
      if ((((bVar1 & 4) == 0) && (iVar3 != 0)) || (((bVar1 & 4) != 0 && (iVar3 == 0)))) {
        param_1[0xe] = 0;
        param_1[1] = 0;
        if ((code *)param_1[0xf] != (code *)0x0) {
          memw();
          (*(code *)param_1[0xf])(param_1,2);
        }
        if ((bVar1 & 4) != 0) {
          return 0;
        }
        FUN_4011ad9c(iVar3);
        return 0;
      }
      pcVar5 = "connect";
      uVar4 = 0x588;
      memw();
    }
    iVar3 = 0;
    if ((param_1[0xd] & 4) != 0) goto LAB_4011c7a8;
    pcVar5 = "CONNECT";
    uVar4 = 0x57b;
  } while( true );
}

