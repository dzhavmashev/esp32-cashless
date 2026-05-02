// Function : FUN_4011ad40
// Address  : 0x4011ad40
// Size     : 88 bytes


undefined4 FUN_4011ad40(int *param_1,byte param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_2 < 2) goto LAB_4011ad5b;
  pcVar3 = "e mutex";
  uVar2 = 0x80;
  while( true ) {
    (*(code *)&SUB_40094c54)("e mutex",uVar2,"_signal",pcVar3);
LAB_4011ad5b:
    iVar1 = (*(code *)&SUB_4008f990)(1,0,3);
    *param_1 = iVar1;
    if (iVar1 == 0) break;
    if ((param_2 != 1) || (iVar1 = (*(code *)&SUB_4008fab8)(iVar1,0,0), iVar1 == 1)) {
      uVar2 = 0;
LAB_4011ad72:
      memw();
      return uVar2;
    }
    pcVar3 = " nor 1)";
    uVar2 = 0x8a;
  }
  uVar2 = 0xff;
  goto LAB_4011ad72;
}

