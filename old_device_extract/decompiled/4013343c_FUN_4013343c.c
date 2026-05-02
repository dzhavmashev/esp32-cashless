// Function : FUN_4013343c
// Address  : 0x4013343c
// Size     : 115 bytes


char FUN_4013343c(char param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  bVar1 = FUN_401862c0(0x41,0x5a,param_1);
  bVar2 = FUN_401862c0(0x61,0x7a,param_1);
  bVar3 = FUN_401862c0(0x30,0x39,param_1);
  bVar4 = FUN_401862c0(0x2b,0x2b,param_1);
  bVar5 = FUN_401862c0(0x2f,0x2f,param_1);
  return (param_1 + 0x11U & bVar5 |
         param_1 + 0x14U & bVar4 |
         param_1 + 5U & bVar3 | param_1 - 0x40U & bVar1 | param_1 + 0xbaU & bVar2) - 1;
}

