// Function : FUN_400fd340
// Address  : 0x400fd340
// Size     : 129 bytes


undefined8 FUN_400fd340(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 in_PRID;
  
  FUN_400f552c(9);
  (*(code *)&SUB_4009386c)(0x3ffc57b0,2,40000,1);
  (*(code *)&SUB_40093c14)(0x3ffc57b0);
  (*(code *)&SUB_40093abc)(0x3ffc57b0,0,10000,1);
  (*(code *)&SUB_40093abc)(0x3ffc57b0,1,10000,3);
  (*(code *)&SUB_40093c38)(0x3ffc57b0);
  (*(code *)&SUB_40093d88)(0x3ffc57b0);
  iVar1 = FUN_4011ef94();
  uVar3 = 0x3ffc57b0;
  uVar4 = 10000;
  if (iVar1 != 0) {
    uVar2 = rsr(in_PRID);
    uVar3 = 0;
    if ((uVar2 >> 0xd & 1) != 0) {
      uVar3 = rer(0);
      wer(uVar3,1);
      uVar3 = rer(1);
      uVar4 = 0x10000;
      wer(uVar3,0x10001);
    }
  }
  return CONCAT44(uVar4,uVar3);
}

